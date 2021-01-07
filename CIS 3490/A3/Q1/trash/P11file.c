  #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int anagram(char array1[], char array2[])
{
    int num1[26] = {0}, num2[26] = {0}, i = 0;

    while (array1[i] != '\0')
    {
        num1[array1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (array2[i] != '\0')
    {
        num2[array2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}

int check(char* s1, char* s2)
{
    int i,j,len1=strlen(s1), len2=strlen(s2), flag=0;

    char arr[len2];
    printf("string 1: %s\nstring 2: %s",s1,s2);
    for(i=0;i<=len1-len2;i++)
    {
        for(j=0;j<len2;j++)
        {
            arr[j]=s1[i+j];
        }
        if(anagram(arr,s2))
            {
              flag++;
              printf("%s\n",s2);
            }
    }
    return flag;
}

int main()
{
    //char array1[100], array2[100];
    FILE *f;                       // to read from a file
    int a[50000];
    //char arr[50000][10],line[10];          // to calculate the time taken
    int i=0,number;
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
      snprintf(temp,10,"%d",a[1]);
      printf("\n\n %d \n\n",a[i-1]);
      printf("\n\n %s \n\n",ch);
      printf("\nno. of anagrams = %d",anagram(temp,ch));
      end = clock();
      double t = (double) (end - start)/ CLOCKS_PER_SEC;
      printf("\nnumber of integers = %d",i);
      printf("\nTime taken for Brute force = %f seconds\n",t);
    return 0;
}
