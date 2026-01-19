#include <xc.h>


void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {    
        if (++count == 20000) // 1sec
        {
            count = 0;
            
           
        }
        
        TMR2IF = 0;
    }
}