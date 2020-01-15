%{
#include<stdio.h>
int linecount = 1, wordcount = 0, charcount = 0;
%}

%%
\n		{ wordcount++; linecount++; }
[\t' ']	{ wordcount++; }
.		{ charcount++; }
%%
int yywrap(){ return 1; }
int main() {
	yyin = fopen("input1.txt", "r");
	yylex();
	printf("Number of lines in input file: %d\n", linecount);
	printf("Number of words in input file: %d\n", wordcount);
	printf("Number of characters in input file: %d\n", charcount);
}