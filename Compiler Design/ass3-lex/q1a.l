%{
#include<stdio.h>
int linecount = 1, wordcount = 0, charcount = 0;
%}

%%
\n		linecount++;
.		;
%%
int yywrap(){ return 1; }
int main() {
	yyin = fopen("input1.txt", "r");
	yylex();
	printf("Number of lines in input file: %d\n", linecount);
}