//Program to create a char file, block file and a FIFO file
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
  mknod(argv[1],S_IFCHR|0777,333);           //To create a char file
  mknod(argv[2],S_IFBLK|0777,444);           //To create ablock file
  mknod(argv[3],S_IFIFO|0777,555);            //To create a FIFO file
  return 0;
}  
