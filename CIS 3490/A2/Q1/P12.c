/*
Name: Dinesh Sainath Koti Reddy
ID # 1025287
CIS 3490 - Assignment 2
*/
#include<stdio.h>
#include<time.h>

int merge(int array[], int temparr[],int m, int n, int r)
{
   int c=0,i=m, j=n, k=m;

   while ((i<=n-1) && (j<=r))             //merging thw two arrays
   {
      if (array[i] <= array[j])
         temparr[k++] = array[i++];
      else
      {
        temparr[k++] = array[j++];
        c+= (n- i);
      }
   }

    while(i<=n-1)
       temparr[k++] = array[i++];

    while(j<=r)
       temparr[k++] = array[j++];

    for(i=m; i <= r; i++)
       array[i] = temparr[i];
    return c;                     // count
}

int sort(int array[], int temparr[], int a, int b) {
   int n,c=0;
   if (b > a)
   {
      n = (b + a)/2;                         //midpoint in array
      c= sort(array,temparr,a, n);       //left array
      c+= sort(array,temparr, n+1, b);   //right array
      c+= merge(array,temparr, a, n+1, b);//merge the sorted arrays
   }
   return c;          // count
}

int Inversions(int array[], int n)
{
   int temparr[n];
   return sort(array, temparr, 0, n - 1);
}

int main() {
	FILE *f;                    // to open a file
  int a[50000];
  clock_t start,end;          // to find the start and end time
  int i=0,number;
  f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A2\\Q1\\data_1.txt","r");
  if(f == NULL)
    printf("File cannot be opened");
  while(fscanf(f,"%d",&number)!=EOF)      //reading each number from file
    {
      a[i]=number;
      i++;
    }
	  start = clock();                  // start time
    printf("\nNumber of inversions are %d",Inversions(a, 50000));
    end = clock();                    // end time
    double t = (double) (end - start)/ CLOCKS_PER_SEC; //calculating time taken
    printf("\nno. of integers: %d",i);
		printf("\nTime taken for divide and conquer: %f secs",t);
		printf("\n");
}
