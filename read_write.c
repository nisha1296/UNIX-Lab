#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
  char c[6];
  int fd;
  fd=open(argv[1],O_RDWR|O_CREAT,0644);
  write(fd,"Hello\n",6);
  lseek(fd,0,SEEK_SET);
  read(fd,c,6);
  printf("%s",c);
}  
