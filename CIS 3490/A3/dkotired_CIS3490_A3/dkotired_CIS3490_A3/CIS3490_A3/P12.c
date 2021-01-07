/*
Name: Dinesh sainath Koti Reddy
ID# 1025287
CIS 3490 Assignment 3
*/
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void sort(char a[])          //to sort the string before checking for anagrams
{
  int i,j,l;
  char Temp;
  l=strlen(a);
  for(i=0;i<l-1;i++)             //selection sort
   {
     for(j=i+1;j<l;j++)
      {
        if(a[i]>a[j])           //swap if element is greater in the array
        {
          Temp  = a[i];
          a[i] = a[j];
          a[j] = Temp;
        }
      }
    }
}

int checkanagram(char filestr[],char userstr[])     //to check if there are occurences of anagram
{
  int i,m,n;
  m = strlen(filestr);
  n = strlen(userstr);

  if(m!=n)
  {
     return 0;
  }
  sort(filestr);
  sort(userstr);
  for(i=0;i<m;i++)
  {
     if(filestr[i]!=userstr[i])
        return 0;
  }
  return 1;
}


int main()
{
  FILE *f;                       // to read from a file
  //int a[50000];
  char number[10];          // to calculate the time taken
  int i=0,count=0;
  clock_t start,end;    //to calculate time
  char ch[20];
  printf("enter string: ");     //user input
  scanf("%s",ch);
  f=fopen("data_4.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
  start = clock();
    while(fscanf(f,"%s",number)!=EOF)        // reading each number/string
      {
        int n = checkanagram(number,ch);   //function call
        if (n==1)
            count++;                   //counts the number of occurences
        i++;
      }
  end = clock();
  double t=(double)(end - start)/CLOCKS_PER_SEC;
  printf("no. of anagrams: %d",count);
  printf("\nTime taken for presort method = %f seconds\n",t);  //time taken
  return 0;
}
