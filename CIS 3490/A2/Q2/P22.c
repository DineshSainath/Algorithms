#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


typedef struct point
{
  float x;
  float y;
}point;

int side(point a, point b, point c)
{
  int p=(c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
  if (p> 0)
    return 1;
  if (p< 0)
    return -1;

  return 1;
}

int Hull(point * P, point * Hpoints, point a, point b, int Count, int Hcount, int s){
  int flag1 = 0,flag2 = 0,i,Temp,d = 0,r = -1;
  for (i=0; i<Count; i++)
  {
    Temp=abs((P[i].x - a.x) * (b.y - a.y) - (P[i].y - a.y) * (b.x - a.x));
    if(side(a, b, P[i])==s && Temp > d)
    {
        r = i;
        d = Temp;
    }
  }
  if (r == -1)
  {

    if (Hcount == 0)
    {
      Hpoints[Hcount++] = a;
      Hpoints[Hcount++] = b;
    }
    else
    {
      for (i=0;i<Hcount;i++)
      {
        if (a.x == Hpoints[i].x && a.y == Hpoints[i].y)
          flag1 = 1;
        if (b.x == Hpoints[i].x && b.y == Hpoints[i].y)
          flag2 = 1;
      }

      if(flag1 == 0)
        Hpoints[Hcount++] = a;
      if (flag2 == 0)
        Hpoints[Hcount++] = b;
    }
    return Hcount;
  }
  Hcount = Hull(P, Hpoints, P[r], a, Count, Hcount, -side(P[r], a, b));
  Hcount = Hull(P, Hpoints, P[r], b, Count, Hcount, -side(P[r], b, a));
  return Hcount;
}

int QHull(point *P, point * Hullpoints, int Count)
{
  int i,Min = 0,Max = 0;
  for (i = 1; i < Count; i++)
  {
    if (P[i].x <P[Min].x)
      Min = i;

    if (P[i].x > P[Max].x)
      Max = i;
  }
  int Hcount = 0;
  Hcount=Hull(P,Hullpoints,P[Min],P[Max], Count, Hcount, 1);
  Hcount=Hull(P,Hullpoints,P[Min],P[Max], Count, Hcount, -1);

  for (int a=0; a< Hcount; a++)
     printf("%.2f  %.2f\n",Hullpoints[a].x,Hullpoints[a].y);
  return Hcount+1;
}

int main()
{
  int Count,Hcount,i=0;
  point points[30000], Hullpoints[30000];
  clock_t start,end;
  float number;
  FILE *f;               //input
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
  Count = i;
  start = clock();
  Hcount = QHull(points, Hullpoints, Count);
  end = clock();
  double t=(end-start)/CLOCKS_PER_SEC;
  printf("\nThe convex hull has %d points", Hcount);
  printf("\nTime taken: %f",t);
  fclose(f);
  return 0;
}
