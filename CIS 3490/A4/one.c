#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define MAXLEN 9

//struct for node
struct node {
    char *value;         // all void* types replaced by char*
    int count;
    struct node *p_left;
    struct node *p_right;
};

//use typedef to make calling the compare function easier
typedef int (*Compare)(const char *, const char *);

/*struct node *newNode(char* item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = strdup(item);
    temp->left = NULL;
    temp->right = NULL;
    temp->count = 1;
    return temp;
};*/
//inserts elements into the tree
void insert(char* key, struct node** leaf, Compare cmp)
{
    int res;
    if( *leaf == NULL )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->value = malloc( strlen (key) +1 );     // memory for key
        //strcpy ((*leaf)->value, key);                   // copy the key
        (*leaf)->value = strdup(key);
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
        (*leaf)->count = 1;
        //printf(  "\nnew node for %s" , key);
    } else {
        res = cmp (key, (*leaf)->value);
        if( res < 0)
            insert( key, &(*leaf)->p_left, cmp);
        else if( res > 0)
            insert( key, &(*leaf)->p_right, cmp);
        else                                            // key already exists
            (*leaf)->count++;
    }
}

//compares value of the new node against the previous node
int CmpStr(const char *a, const char *b)
{
    return (strcmp (a, b));     // string comparison instead of pointer comparison
}

char *input( void )
{
    static char line[MAXLEN+1];       // where to place key
    printf("Please enter a string : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));    // remove trailing newline
}

//recursive function to print out the tree inorder
void in_order(struct node *root)
{
    if( root != NULL )
    {
        in_order(root->p_left);
        printf("   %s\n", root->value);     // string type
        in_order(root->p_right);
    }
}

//searches elements in the tree
void search(char* key, struct node* leaf, Compare cmp)  // no need for **
{
    int res;
    if( leaf != NULL ) {
        res = cmp(key, leaf->value);
        if( res < 0)
            search( key, leaf->p_left, cmp);
        else if( res > 0)
            search( key, leaf->p_right, cmp);
        else
            printf("\n'%s' found!\ncount = %d", key,leaf->count);     // string type
    }
    else printf("\nNot in tree\n");
    return;
}

void delete_tree(struct node** leaf)
{

    //if(strcmp((*leaf)->key,))
    if( *leaf != NULL )
    {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf)->value );
      //  free((*leaf)->count);         // free the key
        free( (*leaf) );
    }
}

//displays menu for user
void menu()
{
    printf("\nPress 'i' to insert an element\n");
    printf("Press 's' to search for an element\n");
    printf("Press 'p' to print the tree inorder\n");
    printf("Press 'f' to destroy current tree\n");
    printf("Press 'q' to quit\n");
}

int main()
{
    struct node *p_root = NULL;
  //  char *value;
  //  char option = 'x';
    FILE *f;                       // to read from a file
    char number[10];          // to calculate the time taken
    int i=0,count=0;
    clock_t start,end;
    char ch[20];
    printf("enter string: ");
    scanf("%s",ch);
    start = clock();
    f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A4\\data_7.txt","r");
    if(f == NULL)
    printf("File cannot be opened");
      while(fscanf(f,"%s",number)!=EOF)        // reading each number/string
        {
          count++;
          insert(number,&p_root,(Compare)CmpStr);
          i++;
        }
    end = clock();
    double t = (double) (end - start)/ CLOCKS_PER_SEC;
    printf("\nTime taken for Brute Force = %f seconds\n",t);
  /*  while( option != 'q' ) {
        //displays menu for program
        menu();

        //gets the char input to drive menu
        option = getch();           // instead of two getchar() calls

        if( option == 'i') {
            value = input();
            printf ("Inserting %s\n", value);
            insert(value,  &p_root, (Compare)CmpStr);
        }
        else if( option == 's' ) {
            value = input();
            search(value, p_root, (Compare)CmpStr);     // no need for **
        }
        else if( option == 'p' ) {
            in_order(p_root);
        }
        else if( option == 'f' ) {
            delete_tree(&p_root);
            printf("Tree destroyed");
            p_root = NULL;
        }
        else if( option == 'q' ) {
            printf("Quitting");
        }
    }*/
return 0;
}
