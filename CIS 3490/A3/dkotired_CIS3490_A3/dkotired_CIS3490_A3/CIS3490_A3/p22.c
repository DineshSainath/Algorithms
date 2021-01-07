/*
Name: Dinesh sainath Koti Reddy
ID# 1025287
CIS 3490 Assignment 3
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int Table[300];
int *Tableshift(char strPattern[30])
{
    int i,j,temp,l;
    l = strlen(strPattern);
    for(i=0;i<300;i++)
    {
        Table[i]=l;
    }
    for (j = 0; j < l -1; j++)
    {
        temp = strPattern[j];
        Table[temp +'0'] = l -1-j;
    }
    return Table;
}

int HorspoolMatch(char strPattern[30],char **dataArray,int Length)
{
  int i = 0,j = 0,count=0,l,nShifts = 0;
  Tableshift(strPattern);        //function call to shift table
  l = strlen(strPattern) - 1;

  for (j=0;j<Length;j++)
  {
    while (l<=strlen(dataArray[j])-1)
    {
        i = 0;
        while(i<=strlen(strPattern)-1 && strPattern[strlen(strPattern)-1-i] == dataArray[j][l-i])
        {
            i++;
        }
        if (i == strlen(strPattern))
        {
            count++;                        // increments when its a match
            nShifts++;                      // character shift increment
            l = l + Table[dataArray[j][l]+'0'];
            if (!(dataArray[j][l]+'0' >= 0 && dataArray[j][l]+'0' <= 300))
            {
                l++;
            }
        }
        else
        {
          nShifts++;                    // character shift increment
          l=l+Table[dataArray[j][l]+'0'];
          if(!(dataArray[j][l]+'0' >= 0 && dataArray[j][l]+'0' <= 300))
          {
              l++;
          }
      }
  }
  l=strlen(strPattern)- 1;
 }
 printf("\nnumber of pattern shifts = %d\n", nShifts);      //total character shifts
 return count;
}

int main()
{
  FILE *f;                       // to read from a file
  //char line[100];          // to calculate the time taken
  int i=0,count=0;
  clock_t start,end;      //to calculate time taken
  char ch[20],fdata[100000];
  printf("Enter a string pattern to search in the text file: ");
  scanf("%s",ch);
  char **filedata = (char**) calloc(44049, sizeof(char*));
  for (int j=0;j<44049;j++)
    {
        filedata[j]=(char*)calloc(90,sizeof(char));
    }
  start = clock();
  f=fopen("data_5.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
  while (fgets(fdata, 100000,f))
  {
      strcpy(filedata[i], fdata);            //storing all the lines into 2D array
      i++;
  }
  count = HorspoolMatch(ch,filedata,i);     //function call for search
	end = clock();
	//printf("\n%s\n",line);
	printf("number of lines: %d",i);
	printf("\nno. of times the pattern is found = %d\n",count);
	//printf("number of pattern shifts: %d",shifts);
	double t = (double) (end - start)/ CLOCKS_PER_SEC;      //time taken
  printf("\nTime taken for Brute force = %f seconds\n",t);
	return 0;
}
