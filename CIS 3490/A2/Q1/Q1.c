#include<stdio.h>
#include<string.h>
#include<time.h>

int bruteforceInv(int a[], int n)
{
    int i,j,count=0;
    for (i=0;i<n-1;i++)
      {  for (j=i+1;j<n;j++)
            {
              if(a[i]>a[j])
                count++;
            }
      }
    return count;
}

int MergeArray(int a[],int l, int m, int r, int temp[])
{
   int count=0,i, j, k;
   i = l;
   j = m;
   k = l;

   while ((i <= m - 1) && (j <= r)) {
      if (a[i] <= a[j]) {    //when left item is less than right item
         temp[k++] = a[i++];
      }else{
         temp[k++] = a[j++];
         count += (m- i);    //find how many convertion is performed
      }
   }

    while (i <= m - 1)    //if first list has remaining item, add them in the list
       temp[k++] = a[i++];

    while (j <= r)    //if second list has remaining item, add them in the list
       temp[k++] = a[j++];

    for (i=l; i <= r; i++)
       a[i] = temp[i];    //store temp Array to main array
    return count;
}

int MergeSort(int a[], int l, int r, int temp[]) {
   int m, count = 0;

   if (r > l) {
      m = (r + l)/2;    //find mid index of the array
      count  = MergeSort(a,l, m,temp);    //merge sort left sub array
      count += MergeSort(a, m+1, r, temp);    //merge sort right sub array

      count += MergeArray(a, l, m+1, r, temp);    //merge two sub arrays
   }
   return count;
}

int arrInversion(int a[], int n) {
   int temp[n];
   return MergeSort(a, 0, n - 1, temp);
}

int main()
{
clock_t start,end;
double t1,t2;
int n,a[] = {1, 20, 6, 4, 5};
n=sizeof(a)/sizeof(a[0]);
start= clock();
printf("no. of inversions by BruteForce = %d ", bruteforceInv(a, n));
end= clock();
t1 = (double)(end-start)/CLOCKS_PER_SEC;
  printf("\nTime taken for Brute Force: %f\n\n",t1);
start= clock();
printf("\nNumber of inversions are %d",arrInversion(a, n));
end= clock();
t2 = (double)(end-start)/CLOCKS_PER_SEC;
printf("\nTime taken for divide and conquer: %f\n",t2);
return 0;
}
