#include <stdio.h>
#include <string.h>

int n;
char name[20];

struct relation{
char child[20];
char father[20];
}r[20];

int count=0;
void grandchildren(char name[])
{
	int j;
	for(j=1;j<10;j = j + 2)
	{
		if(strcmp(name,r[j].father) == 0)
		{
			count++;
		}
	}
}


int main()
{
	FILE *fp;
	char c,str[200],s[5][15];
	int i = 0,j,l = 0;
	    
	fp = fopen("file.txt","r");
	do
	{
		c = getc(fp);
		str[i++] = c;
	}while(c != EOF);
	fclose(fp);
	    
	int init_size = strlen(str);
	char delim1[] = "\n";

	char *ptr1 = strtok(str, delim1);
	while(ptr1 != NULL)
	{
		strcpy(s[j++],ptr1);
		ptr1 = strtok(NULL, delim1);
	}
		
	char delim2[] = " ";
	char *ptr2;
		
	for(int k = 0;k<10;k++)
	{
		ptr2 = strtok(s[k], delim2);
		while(ptr2 != NULL)
		{
		if(l%2 == 0)
		{
			strcpy(r[l++].child,ptr2);
		}
		else 
		{
			strcpy(r[l++].father,ptr2);
		}
		ptr2 = strtok(NULL, delim2);
		}
	}

	printf("Input: ");
	scanf("%s",name);
	for(int q=1;q<10;q = q + 2)
	{
		if(strcmp(r[q].father,name) == 0) { grandchildren(r[q - 1].child); }
	}
	printf("Output: %d\n",count);

	return 0;
	    
}
