/*
Name: Dinesh sainath Koti Reddy
ID# 1025287
CIS 3490 Assignment 3
*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<time.h>

int max(int a, int b)     // to find the largest of two numbers
{
  int Max;
  if(a>b)
    Max =a;
  else
    Max =b;
  return Max;
}

void BadchHeuristics(int Badch[256],char *str, int length)
{   //the characters that are not part of the pattern are bad characteristics.
    int j;
    for(j=0;j<256;j++)
        Badch[j] = -1;      ///initalizing all elements to -1

    for(j=0;j<length;j++)
         Badch[(int)str[j]]=j;
}

int Boyersearch(char *txt, char *pat, int* nshifts)
{
    int m,n,temp,count=0,shifts=0;
    int i,Badch[256];
    m = strlen(pat);
    n = strlen(txt);

    BadchHeuristics(Badch,pat, m);        // call to get bad characters

    while(shifts<=(n-m))
    {
        i = m-1;
        while((i>=0) && (pat[i]==txt[shifts+i]))
            i--;

        if(i<0)
        {
            count++;                            //if i<0, then its a maatch
            temp = txt[shifts+m];
            shifts += (shifts+m < n)? m-Badch[temp] : 1;          //pattern shift

        }

        else
          {
            temp = txt[shifts+i];                //shift the pattern
            shifts+= max(1,i-Badch[temp]);       // to find the required in text file
          }
      }
      *nshifts = shifts;    // shifts for the particular line
      return count;         // number of occurences
}

int main()
{
  FILE *f;                       // to read from a file
  char line[100];               //to read a line from the file
  int i=0,count=0,nshifts=0,shifts=0; //shifts - shift for each line; nshifts = total shifts
  clock_t start,end;       // to calculate the time taken
  char ch[20];            //user input
  printf("Enter a string pattern to search in the text file: ");
  scanf("%s",ch);
  start = clock();
  f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A3\\data_5.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
    while(fgets(line,100,f))        // reading each line
      {
        count+= Boyersearch(line,ch,&nshifts);        //Boyer Moore function call
        shifts+=nshifts;                       //adding the shifts
        i++;
      }
  end = clock();
  printf("\n%s\n",line);
  printf("\nnumber of lines: %d",i);
  printf("\nno. of times the pattern is found = %d\n",count);
  printf("number of pattern shifts: %d",shifts);
  double t = (double) (end - start)/ CLOCKS_PER_SEC;          //time taken
  printf("\nTime taken for Boyer Moore search = %f seconds\n",t);
  return 0;
}
