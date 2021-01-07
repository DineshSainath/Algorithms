#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void Ttable(int wordLen, char * word, int table[]){

	int k;
	int j;

	for(k = 0; k <127; k++){ /*fill in the ascii table*/
		table[k] = wordLen; // default mode
	}


	for(j = 0; j<wordLen-1; j++){
		char b = word[j];
		int ch = (int)b;
			table[ch] = wordLen - 1 - j; // special shift

	}
}
	int horspool(char * strchar, char* word,int table[]){

		int count = 0;
		int k,wordLen,stringLength;
		wordLen = strlen(word);
		stringLength=strlen(stringLength);
		for(k = 0; k<stringLength; k++){

			if(word[wordLen-1] != str[k+ wordLen-1]){ // if the end is not equal
				char a = str[k+ wordLen-1];
				int ah = (int)a;
				k = k + table[ah]-1;
			}else { /*If the end char is the same */
				int p = 0; // count the number of equal letter
				int bb = wordLen-1;
				while(bb >=0){ /*check string*/
					if(word[bb] == str[k+ bb]){
						p++;
					}
					bb--;
				}

				if(p == wordLen){
					count++;
				}
				char a = str[k+ wordLen-1];
				int ah = (int)a;
				k = k + table[ah]-1;
			}
		}

		return count;
	}
int main()
{
	FILE *f;                       // to read from a file
  //int a[50000];
  char line[100];          // to calculate the time taken
  int i=0,pos=0,table[150],count=0,nshifts=0,shifts=0;
  clock_t start,end;
  char ch[20];
  printf("enter string pattern to search: ");
  scanf("%s",ch);
	int l =strlen(ch);
  start = clock();
	Ttable(l,ch,table);
  f=fopen("C:\\Users\\Pams\\Documents\\DS\\CIS 3490\\A3\\data_5.txt","r");
  if(f == NULL)
  printf("File cannot be opened");
    while(fgets(line,100,f))        // reading each number
      {
				count+=horspool(line,ch);
			//	shifts+=nshifts;
				i++;
      }
	end = clock();
	printf("\n%s\n",line);
	printf("\nnumber of lines: %d",i);
	printf("\nno. of times the pattern is found = %d\n",count);
	printf("number of pattern shifts: %d",shifts);
	double t = (double) (end - start)/ CLOCKS_PER_SEC;
  printf("\nTime taken for Brute force = %f seconds\n",t);
	return 0;

}
