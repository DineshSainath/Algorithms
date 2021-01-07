/*
Name: Dinesh sainath Koti Reddy
ID# 1025287
CIS 3490 Assignment 3
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int BFanagram(char* str1, char* str2)     //To find the number of anagrams
{                                         // by bruteforce
    int chars[256] = {0};
    int i,temp;
    for (i = 0; str1[i] && str2[i]; i++)
    {
        temp = str1[i];                 //checking if characters are same
        chars[temp]++;                  // and storing in chars[]
        temp = str2[i];                 //to check each anagram
        chars[temp]--;
    }
    if (str1[i] || str2[i])           //match check
        return 0;                     //return 0 if not a match

    for (i = 0; i < 256; i++)
        if (chars[i])                 //match check
            return 0;

    return 1;                        // return 1 if its a match
}

int main()
{
  FILE *f;                       // to read from a file
  char number[10];          // to calculate the time taken
  int i=0,count=0;
  clock_t start,end;
  char ch[20];
  printf("enter string: ");
  scanf("%s",ch);
  start = clock();
  f=fopen("data_4.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
    while(fscanf(f,"%s",number)!=EOF)        // reading each number/string
      {
        int n = BFanagram(number,ch);    ///bruteforce function call
        if (n==1)
            count++;                  // counts the number of occurences
        i++;
      }
  printf("\nno. of anagrams: %d",count);
  end = clock();
  double t = (double) (end - start)/ CLOCKS_PER_SEC;
  printf("\nTime taken for Brute Force = %f seconds\n",t);   //time taken
  return 0;
}
