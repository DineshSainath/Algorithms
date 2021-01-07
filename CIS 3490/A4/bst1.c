#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    int count;
    char* key;
    struct node* left;
    struct node* right;
};

struct node *newNode(char* item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = strdup(item); // <--- here!
    /* TODO: Error-handling! */
    temp->left = NULL;
    temp->right = NULL;
    temp->count = 1;
    return temp;
}

void printInorder(struct node* root)
{
    if(root != NULL)
    {
        printInorder(root->left);
        printf("%s \n", root->key);
        printInorder(root->right);
    }
}

struct node* insert(struct node* node, char* key)
{
    if(node == NULL)//When tree is empty
        return newNode(key);
    if(strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if(strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);
    else
      node->count++;
    return node;
}


void search(struct node* node,char *key, int total,int min)
{
  int c=strcmp(key,node->key);
  float p;
  if(node!=NULL)
  {
    if(c<0)
      {
        min++;
        printf("\nCompared with %s, go left subtree.",node->key);
        search(node->left,key,total,min);
        //min++;
      }
    else if(c>0)
      {
        min++;
        printf("\nCompared with %s, go right subtree.",node->key);
        search(node->right,key,total,min);
      }
    else
      {
        min++;
        printf("\nCompared with %s, found.",node->key);
        printf("\nminimum comparisons: %d\n",min);    //DEBUG THIS
        printf("\n%s found %d times",key,node->count);
        p = (float)node->count/total;
        printf("\nprobability = %f\n",p);
      }
  }
  else
    printf("\nnot in the tree\n");
}


int main()
{
  struct node *root = NULL;
  int i,j,min=0,n=0,c=0;
  char array[2045][25],sarray[2045][25],temp[20];
  int p[4025];
  printf("\nEnter a string to search: ");
  scanf("%s",temp);
  char *arr = temp;
  FILE* fp;
  fp = fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A4\\data_7.txt", "r");
  if ((fp = fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A4\\data_7.txt","r")) == NULL)
  {
    printf("Could not open textFile.txt\n");
    exit(1);
  }

  while(fscanf(fp,"%s",sarray[n]) != EOF)
  {
    ++n;
      //  printf("%3d: %s", i, str);
  }

  for(i=0;i<n;i++)
  {
    strcpy(array[i],sarray[i]);
  }

  for(i=0;i<=n;i++)
  {
    for(j=i+1;j<=n;j++)
    {
      if(strcmp(sarray[i],sarray[j])>0)
      {
        strcpy(temp,sarray[i]);
        strcpy(sarray[i],sarray[j]);
        strcpy(sarray[j],temp);
      }
    }
  }

  for(i=0;i<n;i++)
  {
      p[i] = 0;
      strcpy(temp,sarray[i]);
      for(j=0;j<n;j++)
      {
        if(strcmp(sarray[i],sarray[j]))
        p[i]++;
      }
      printf("\nprob: %d",p[i]);
  }



  for(i=0;i<n;i++)
  {
    root = insert(root,array[i]);
  }

  printf("\ntotal = %d", i);
  search(root,"undergraduate",n,min);

  return 0;
}
