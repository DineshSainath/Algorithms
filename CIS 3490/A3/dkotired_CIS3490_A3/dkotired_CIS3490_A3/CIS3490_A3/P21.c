/*
Name: Dinesh sainath Koti Reddy
ID# 1025287
CIS 3490 Assignment 3
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
int bruteForceSearch(char* strPattern, char* txtLine,int* nshifts)
{
  int i,j,m,n,count=0,shifts=0;
  m = strlen(strPattern);        //string length of the pattern and
  n = strlen(txtLine);       // string length of the line from text file
  for(i=0;i<=n-m;i++)
	 {
      for (j=0;j<m;j++)
        {
					shifts++;             // shift to each character
					if (txtLine[i+j]!=strPattern[j])
						 break;
				}
      if (j==m)
			  count++;
		}
		*nshifts= shifts;
		return count;
}

int main()
{
  FILE *f;                       // to read from a file
  //int a[50000]
  char line[100];          // to calculate the time taken
  int i=0,count=0,nshifts=0,shifts=0;//shifts - shift for each line; nshifts = total shifts
  clock_t start,end;      //to calculate time taken
  char ch[20];
  printf("Enter a string pattern to search in the text file: ");
  scanf("%s",ch);
  start = clock();
  f=fopen("data_5.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
    while(fgets(line,100,f))        // reading each line
      {
				count+=bruteForceSearch(ch,line,&nshifts);    //adds the number of occurences from brute force
				shifts+=nshifts;                  // total shifts
				i++;
      }
	end = clock();
	printf("\n%s\n",line);
	printf("\nnumber of lines: %d",i);
	printf("\nno. of times the pattern is found = %d\n",count);
	printf("number of pattern shifts: %d",shifts);
	double t = (double) (end - start)/ CLOCKS_PER_SEC;      //time taken
  printf("\nTime taken for Brute force = %f seconds\n",t);
	return 0;
}
