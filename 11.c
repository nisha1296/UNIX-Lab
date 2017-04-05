#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int parsecondition(char input[],int c,char *dest,int len)
{
  int start=0,pos=0;
  while(input[c]!='('&&c<=len)
    c++;
  if(c>=len)
    return 0;
  start=c;
  while(input[c]!=')'&&c<=len)
    c++;
  if(c>=len)
    return 0;    
  while(start<=c)
    dest[pos++]=input[start++];
  dest[pos]='\0';
  return c;
}

void gen(char b[],char s1[],char s2[],int flag)
{
  int lno1=101,lno2=102,lno3=103;
  printf("\n\tif %s goto %d\n",b,lno1);
  printf("\n\tgoto %d\n",lno2);
  printf("\n%d: %s",lno1,s1);
  if(!flag)
    printf("\n%d:\n",lno2);
  else
  {
    printf("\n\tgoto %d",lno3);
    printf("\n%d: %s",lno2,s2);
    printf("\n%d: \n",lno3);
  }
}

int main()
{
  int c=0,len=0,flag=0;                                      
  char statement[60],ifcond[60],ifres[60],elseres[60];                           
  printf("Enter the statement: \n");
  scanf("%[^\n]",statement);
  len=strlen(statement);
  c+=2;
  c=parsecondition(statement,c,ifcond,len);            
  if(statement[c]==')')
    c++;
  c=parsecondition(statement,c,ifres,len);
  if(statement[c+1]==';')
  {
    printf("\nParsing the input statement: \n");
    gen(ifcond,ifres,elseres,flag);
    return 0;
  }
  if(statement[c]==')')
    c++;
  c=parsecondition(statement,c,elseres,len);
  c+=2;
  if(c==len)
  {
    flag=1;
    gen(ifcond,ifres,elseres,flag);
    return 0;
  }
  return 0;
}              
