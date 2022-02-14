#include<stdio.h>

typedef unsigned u;

char S[100];u l=1;
int main()
{
	char c;
	printf("Enter string:");
	while((c=getchar())<'a');
	do
	{
		S[l]=c;
		if(S[l]==S[l-1])--l;
		else++l;
	}
	while((c=getchar())>='a');
	S[l]='\0';
	printf("%s\n",l-1?S+1:"Empty String");
	return 0;
}
