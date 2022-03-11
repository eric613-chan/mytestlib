#include <stdio.h>

void* mymemcpy(void* dest, void* src, size_t count)
{
    void* retval = dest;
    char* d = (char*)dest;
    char* s = (char*)src;
    
    // make sure src and dest are all valid pointer,
    // and if d == s, no need copy anything
    if(!d || !s || d == s)
     {
         return retval;
     }

     // heap grows from low-address to high address, 
     // src and dest are the beginning address,
     // consider memoryi-overlapping cases:
     // a) d < s
     //    if d + count <= s, no overlap at all, else overlap a part.
     // b) d == s
     //    no need copy anthing
     // c) d > s && d < s + count
     //    copy should be started from high-address
     // d) d >= s + count 
     //    no overlap at all
     //
     if(d > s && d < s + count)
     {
         // need make copy from high-address
         while(count--)
         {
             *(d + count) = *(s + count);
         }
     }
     else
     {
         // need make copy from low-address
         while(count--)
         {
             *d++ = *s++;
         }
     }
    return retval;
}
