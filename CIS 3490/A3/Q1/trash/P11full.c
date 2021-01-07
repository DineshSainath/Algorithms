#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int anagram(char array1[], char array2[])
{
  int i,j,found,len,len1=strlen(array1);
  int len2=strlen(array2);
  if(len1==len2)
  {
    len=len1;
    for(i=0;i<len;i++)
    {
      found=0;
      for(j=0;j<len;j++)
      {
        if(array1[i]==array2[j])
        {
          found=1;
          break;
        }
      }
    }
  }
  return found;
}
int check(int a[30000], char k[20])
{
    int count=0,i=0,n=0;
    char temp[20];
    printf("\nAnagrams: ");
    for(i=0;i<30000;i++)
    {
      snprintf(temp,20,"%d",a[i]);
      n = anagram(temp,k);
      if(n==1)
      {
         printf("%d\t%d\n",a[i],n);
         count++;
      }
    }
    return count++;
}

int main()
{
    //char array1[100], array2[100];
    FILE *f;                       // to read from a file
    int a[50000];
    //char arr[50000][10],line[10];          // to calculate the time taken
    int i=0,number,count=0;
    clock_t start,end;
    char ch[20];
    printf("enter string: ");
    scanf("%s",ch);
    start = clock();
    f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A3\\data_4.txt","r");
    if(f == NULL)
    printf("File cannot be opened");
      while(fscanf(f,"%d",&number)!=EOF)        // reading each number
        {
          a[i]=number;
          i++;
        }
    char temp[10];
    snprintf(temp,10,"%d",a[0]);
    printf("\n\n %d \n\n",a[i-1]);
    printf("\n\n %s \n\n",ch);
    count = check(a,ch);
    end = clock();
    double t = (double) (end - start)/ CLOCKS_PER_SEC;
    printf("\nnumber of integers = %d",i);
    printf("\nnumber of anagrams: %d",count);
    printf("\nTime taken for Brute force = %f seconds\n",t);
    return 0;
}
