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

void Search(struct Node* node,char *data, int total,int min)    // to search the work in the tree
{
  int c=strcmp(data,node->data);
  float p;
  if(node!=NULL)
  {
    if(c<0)
    {
      min++;
      printf("\nCompared with %s, go left subtree.",node->data);
      Search(node->Left,data,total,min);
      //min++;
    }
    else if(c>0)
    {
      min++;
      printf("\nCompared with %s, go right subtree.",node->data);
      Search(node->Right,data,total,min);
    }
    else
    {
      min++;
      printf("\nCompared with %s, found.",node->data);
      printf("\nminimum comparisons: %d\n",min);
      printf("\n%s found %d times",data,node->count);
      p = (float)node->count/total;
      printf("\nprobability = %f\n",p);       //probability of the word in the file
    }
  }
  else
    printf("\nnot in the tree\n");
  }
int main()
{
  struct Node *root = NULL;
  int min=0,i=0;
  char str[20],temp[20];
  printf("\nEnter a string to search: ");
  scanf("%s",temp);                 //user input
  char *arr = temp;
  FILE* fp;                   // to open the text file
  fp = fopen("data_7.txt", "r");
  if ((fp = fopen("data_7.txt","r")) == NULL)
  {
    printf("Could not open the file.txt\n");
    exit(1);
  }

  while(fscanf(fp,"%s",str) != EOF)
  {
      ++i;
      root = insert(root, str);             //insering elements into the tree
  }

  printf("\ntotal = %d", i);

  Search(root,arr,i,min);                //calling the search function

  return 0;
}
