#include<reg51.h>
void msdelay(unsigned int time)
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void main()
{
    unsigned char no_code[]={0xC0,0xA4,0x99,0x82,0x80};
    int k;
    while(1)
    {
        for(k=0;k<10;k++)
        {
         P2=no_code[k]; 
         msdelay(100);
        }
    }
}