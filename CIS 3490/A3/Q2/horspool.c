#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int horspool(char *t,char *p,int* nshifts)
{
  int n,m,i,j,k,count=0,shifts=0,table[126];
  n=strlen(t);
  m=strlen(p);
  int temp;
//  char t[100];
//  strcpy(t,txt);
  for(i=0;i<126;i++)
   table[i]=m;
  for(j=0;j<m-2;j++)
  {
    temp = p[j];
    table[temp]=m-1-j;
  }
  i=m-1;
  while(i<=n-1)
  {
    k=0;
    while(k<=m-1 && p[m-1-k]==t[i-k])
    {
      shifts++;
      k++;
    }
    if(k==m)
      {
        printf("The postion of the pattern is %d\n",i-m+2);
        count++;//flag=1;
        break;
      }
    else
    {
      temp = t[i];
      i=i+table[temp];
    }
  }
  //if(!flag)
  //printf("Pattern is not found in the given text ");
  *nshifts= shifts;
  return count;
}


int main()
{
  FILE *f;                       // to read from a file
  //int a[50000];
  char line[100];          // to calculate the time taken
  int i=0,count=0,nshifts=0,shifts=0;
  clock_t start,end;
  char ch[20];
  printf("enter string pattern to search: ");
  scanf("%s",ch);
  start = clock();
  f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A3\\data_5.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
    while(fgets(line,100,f))        // reading each number
      {
        count+=horspool(line,ch,&nshifts);
        shifts+=nshifts;
        i++;
      }
  end = clock();
  printf("\n%s\n",line);
  printf("\nnumber of lines: %d",i);
  printf("\nno. of times the pattern is found = %d\n",count);
  printf("number of pattern shifts: %d",shifts);
  double t = (double) (end - start)/ CLOCKS_PER_SEC;
  printf("\nTime taken for Brute force = %f seconds\n",t);
  return 0;
}
