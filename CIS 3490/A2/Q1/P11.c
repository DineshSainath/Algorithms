/*
Name: Dinesh Sainath Koti Reddy
ID # 1025287
CIS 3490 Assignment 2
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Finding the number of inversions by Brute Force method
int bruteforceInv(int a[], int n)
{
    int i,j,count=0;
    for (i=0;i<n-1;i++)
      {  for (j=i+1;j<n;j++)
            {
              if(a[i]>a[j])         // comparison against each element
                count++;
            }
      }
    return count;
}

int main()
{
  FILE *f;                       // to read from a file
  int a[50000];
  clock_t start,end;            // to calculate the time taken
  int i=0,number;
  f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A2\\Q1\\data_1.txt","r");
  if(f == NULL)
    printf("File cannot be opened");
  while(fscanf(f,"%d",&number)!=EOF)        // reading each number
    {
      a[i]=number;
      i++;
    }
start = clock();
printf("\nno. of inversions: %d",bruteforceInv(a,50000));
end = clock();
double t = (double) (end - start)/ CLOCKS_PER_SEC;    //calculating time
printf("\nno.of integers = %d\n",i);
printf("\nTime taken for Brute force = %f seconds\n",t);
return 0;
}
