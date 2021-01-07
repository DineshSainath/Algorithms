#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int t[500];
void shifttable(char p[]) {
	int i,j,m,temp;
	m=strlen(p);
	for (i=0;i<500;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	{
		temp = p[j];
	  t[temp]=m-1-j;
	}
}
int horspool(char src[],char p[])
{
	int i,k,m,n,temp;
	n=strlen(src);
	m=strlen(p);
	shifttable(p);
	//printf("\nLength of text=%d",n);
	//printf("\n Length of pattern=%d",m);
	i=m-1;
	while(i<n) {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		   k++;
		if(k==m)
		{
		   return(i-m+1);
//			 exit (0);
		}
		else
		{
			 temp = src[i];
		   i+=t[temp];
		}
	}
	return -1;
}

int main()
{
	FILE *f;                       // to read from a file
  //int a[50000];
  char line[100];          // to calculate the time taken
  int i=0,pos=0,count=0,nshifts=0,shifts=0;
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
				pos=horspool(line,ch);
				if(pos>=0)
				  count++;
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
