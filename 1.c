#include<stdio.h>
#include<unistd.h>
int main()
{
  int res;
  if((res=sysconf(_SC_CLK_TCK))==-1)
    perror("Error\n");
  else
    printf("Number of clock ticks: %d\n",res);
  if((res=sysconf(_SC_CHILD_MAX))==-1)
    perror("Error\n");
  else
    printf("Maximum number of child processes: %d\n",res);
  if((res=pathconf("/",_PC_PATH_MAX))==-1)
    perror("Error\n");
  else
    printf("Maximum path length: %d\n",res);
  if((res=pathconf("/",_PC_NAME_MAX))==-1)
    perror("Error\n");
  else
    printf("Maximum number of characters in a filename: %d\n",res);  
  if((res=sysconf(_SC_OPEN_MAX))==-1)
    perror("Error\n");
  else
    printf("Maximum number of open files/process: %d\n",res);
  return 0;
}      
      
