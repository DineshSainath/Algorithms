/*
Name: Dinesh sainath Koti reddy
Id # 1025287
CIS*3490 Assignment 4
*/
#include <string.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{                                       // node struct
  struct Node* Left;
  struct Node* Right;
  int count;                          //frequency
  char* data;
};

struct Node *newNode(char* item)               // to create a new node
{
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = strdup(item);
  temp->Right = NULL;
  temp->count = 1;
  temp->Left = NULL;
  return temp;
}

struct Node* insert(struct Node* TreeNode, char* data)   // to insert the node in the tree
{
  if(TreeNode == NULL)             //When the Tree is Empty
      return newNode(data);
  if(strcmp(data,TreeNode->data) < 0)
      TreeNode->Left = insert(TreeNode->Left, data);
  else if(strcmp(data,TreeNode->data) > 0)
      TreeNode->Right = insert(TreeNode->Right, data);
  else
    TreeNode->count++;
  return TreeNode;
}

int Search(struct Node* node,char *data, int total,int min)   // to search for the word in the tree
{
  min++;             // to keep count of minimum comparisons
  float p;
  static int s=0;
  p = (float)node->count/min;
  int c=strcmp(data,node->data);
  if(node!=NULL && min<588)
  {
    if(c<0)
    {
      printf("\nmin: %d Compared with %s, (%f) go left subtree.",min,node->data,p);
      Search(node->Left,data,total,min);
      //min++;
    }
    else if(c>0)
    {
      printf("\nmin: %d Compared with %s, (%f) go right subtree.",min,node->data,p);
      Search(node->Right,data,total,min);
    }
    else if(c == 0)
    {
      s=1;
      printf("\nCompared with %s, found.",node->data);
      printf("\nminimum comparisons: %d\n",min);
      printf("\n%s found %d times",data,node->count);
      p = (float)node->count/total;
      printf("\nprobability of ''%s' in the whole file = %f\n",node->data,p);
      return s;
    }
  }
  else
    s=0;
  return s;
}
int main()
{
  struct Node *Tree = NULL;
  int s,min=0,i=0,j=0,n=0;
  char temp1[20],temp[20],array[2045][20];
  printf("\nEnter a string to search: ");
  scanf("%s",temp1);                  //user input
  char *arr = temp1;
  FILE* fp;                   // text file
  fp = fopen("data_7.txt", "r");
  if ((fp = fopen("data_7.txt","r")) == NULL)
  {
    printf("Could not open the file\n");
    exit(1);
  }

  while(fscanf(fp,"%s",array[n]) != EOF)
  {
    ++n;
  }

  for(i=0;i<=n;i++)
  {
    for(j=i+1;j<=n;j++)
    {
      if(strcmp(array[i],array[j])>0)                  // sort the words
      {
        strcpy(temp,array[i]);
        strcpy(array[i],array[j]);
        strcpy(array[j],temp);
      }
    }
  }

  for(i=0;i<n;i++)
  {
      Tree = insert(Tree,array[i]);            // insert sorted elements into the tree
  }

  s = Search(Tree,arr,i,min);                 //search

  if(s==0)
    printf("\n\tNOT FOUND\n");

  return 0;
}
