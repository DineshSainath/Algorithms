#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<process.h>

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

struct node* search(struct node* node,char *key, int total,int min)
{
  float p;
  //static int s=0;
  struct node* temp = node;
  min++;
  p = (float)node->count/min;
  int c=strcmp(key,node->key);

  if(node!=NULL)
  {
    if(c<0)
      {
        printf("\nCompared with %s, (%f) go left subtree.",node->key,p);
        search(node->left,key,total,min);
        //min++;
      }
    else if(c>0)
      {

        printf("\nCompared with %s, (%f) go right subtree.",node->key,p);
        search(node->right,key,total,min);
      }
    else if(c == 0)
      {
        s=1;
        printf("\nCompared with %s, found.",node->key);
        printf("\nminimum comparisons: %d\n",min);
        printf("\n%s found %d times",key,node->count);
        p = (float)node->count/total;
        printf("\nprobability of ''%s' in the whole file = %f\n",node->key,p);

      }
  }
  return s;
}
int main()
{

    struct node *root = NULL;
    int s,min=0,i=0,j=0,n=0;
    char temp[20],array[2045][20];

    FILE* fp;
    fp = fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A4\\data_7.txt", "r");
    if ((fp = fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A4\\data_7.txt","r")) == NULL)
    {
        printf("Could not open textFile.txt\n");
        exit(1);
    }

    while(fscanf(fp,"%s",array[n]) != EOF)
    {
        ++n;
        //root = insert(root, str);
      //  printf("%3d: %s", i, str);
    }

    for(i=0;i<=n;i++)
    {
      for(j=i+1;j<=n;j++)
      {
        if(strcmp(array[i],array[j])>0)
        {
          strcpy(temp,array[i]);
          strcpy(array[i],array[j]);
          strcpy(array[j],temp);
        }
      }
    }

    for(i=0;i<n;i++)
    {
//      printf("\n%d. %s\n",i,array[i]);
        root = insert(root,array[i]);
    }
    //printInorder(root);
  //  printf("\ntotal = %d", i);
    printf("\nEnter a string to search: ");
    scanf("%s",temp);
    char *arr = temp;
  //  printf("\n%s\n",arr);

    s = search(root,arr,i,min);
    if(s==0)
      printf("\n not found\n");

    return 0;
}
