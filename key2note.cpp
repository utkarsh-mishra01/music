#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<dirent.h>
#include<linux/input.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<sys/time.h>
#include<termios.h>
#include<signal.h>
#include<iostream>
#include<cmath>
#include<stdint.h>
const double R=16000;
const double V=150;
const int run=10000;
void noteC()
{
    int i=0;
    const double C=130.82;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
//////////////////////////////////////////////////////////////////////////
void noteD()
{
    int i=0;
    const double C=146.83;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
///////////////////////////////////////////////////////////////////////////
void noteE()
{
    int i=0;
    const double C=164.83;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
////////////////////////////////////////////////////////////////////
void noteF()
{
    int i=0;
    const double C=174.61;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
///////////////////////////////////////////////////////////////////////////
void noteG()
{
    int i=0;
    const double C=196;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
///////////////////////////////////////////////////////////////////////
void noteA()
{
    int i=0;
    const double C=220;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
//////////////////////////////////////////////////////////////////////////
void noteB()
{
    int i=0;
    const double C=246.94;
    for(i=0;i<run;i++)
    {
        uint8_t temp = (sin (i*2*M_PI/R*C)+1)*V;
        std::cout<<temp;
    }
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
void handler(int sig)
{
    printf("exiting....(%d)n",sig);
    exit(0);
}

void perror_exit(char *error)
{
    perror (error);
    handler (9);
}

int main(int argc,char *argv[])
{
    struct input_event ev;
    int fd,rd,value,size=sizeof(struct input_event);
    char name[256]="Unknown";
    char *device=NULL;

    //check the path
    if(argv[1]==NULL)
    {
        printf("Please specify at the command line: path for event file ");
        exit(0);
    }
    if(getuid()!=0)
        printf("You are not root! This may not work");

    if(argc>1)
        device=argv[1];
    //open the device file
    if((fd=open(device,O_RDONLY))==-1)
        printf("This is not a valid device");
    //print device name
//    printf("reading from:%s (%s)",device,name);
    while(1)
    {
        if((rd=read(fd,&ev,size))<size)
                perror_exit("read()");
       
       
//      
        
        if(ev.value==0 && ev.type==1)
        {
        //printf("code[%d]\n",(ev.code));
        if(ev.code==16)
            noteC();
        if(ev.code==17)
            noteD();
        if(ev.code==18)
            noteE();
        if(ev.code==19)
            noteF();
        if(ev.code==20)
            noteG();
        if(ev.code==21)
            noteA();
        if(ev.code==22)
            noteB();
        }
                
        }
        return 0;
    }






