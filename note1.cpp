#include<iostream>
#include<cmath>
#include<stdint.h>
int main()
{
    const double R=8000;
    const double C=164.86;
    const double F=R/256;
    const double V=127;
    for(int t=0;;t++)
    {
        uint8_t temp = (sin(t*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
    return 0;
}
