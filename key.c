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
    printf("reading from:%s (%s)",device,name);
    while(1)
    {
        if((rd=read(fd,&ev,size))<size)
                perror_exit("read()");
       // value=ev.value;
       // printf("The value is:%d\n:the type is:%d\nThe code is:%d\n",value,ev.type,ev.code);
//        printf("\n----------------\n");
        
        if(ev.value==0 && ev.type==1)
        {
        printf("code[%d]\n",(ev.code));
  //      printf("==========================================\n");
        }
                
        }
        return 0;
    }






