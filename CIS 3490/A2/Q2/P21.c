/*
Name: Dinesh Sainath Koti Reddy
ID # 1025287
CIS 3490 - Assignment 2
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
// convex hull by brute force
typedef struct point            // coordinates
{
       float x;
       float y;
}point;

float Hullplane(point a, point b, point c)     //orientation
{
    float h = (b.y - a.y) * (c.x - b.x)-(b.x - a.x) * (c.y - b.y);
    if(h==0)
      return 0;
    if(h>0)
      return 1;
    else
      return 2;
}

int main()
{
      clock_t start,end;         //to find the time taken for algorithm
       int num,i=0,a=0,b=0,c,count=0;;
       point points[30000];          // to store all the numbers from file
       float number;
       FILE *f;                  // input
       f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A2\\Q2\\data_2.txt","r");
       if(f == NULL)
         printf("File cannot be opened");
       while(fscanf(f,"%f",&number)!=EOF)
         {
           points[i].x = number;              // x coordinate
           fscanf(f,"%f",&number);
          points[i].y = number;              //y coordinate
           i++;
         }
         fclose(f);
       printf("\nnumber of integers: %d\n",i);
       num=i;
       for(i=1;i<num;i++)
       {
              if(points[a].x > points[i].x)
              {
                     a = i;
              }
              else if(points[a].x==points[i].x && points[a].y > points[i].y)
              {
                     a = i;
              }
       }
       c=a;
       b=(a+1)%num;
       start = clock();          //start time
        do
        {                // hull orientation
                printf("%.2f  %.2f\n",points[a].x,points[a].y);
                count++;
                for(i=0;i<num;i++)
                {
                  if(Hullplane(points[a],points[i],points[b])==2)
                    b=i;
                }
                 a=b;
                 b=(a+1)%num;
        }while(a!=c);
        end = clock();                // end time
        double t =(double) (end-start)/ CLOCKS_PER_SEC;
        printf("number of points = %d",count);
        printf("\nTime taken for convex hull process: %f seconds\n",t);
        return 0;
}
