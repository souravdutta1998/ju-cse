%{
#include<stdio.h>
int integernumbers = 0, floatingnumbers = 0;
%}

%%
[+-]?[0-9]+"."[0-9]+ { floatingnumbers++; }
[+-]?[0-9]+ { integernumbers++; }
\n	;
. 	;
%%
int yywrap() { return 1; }
int main() {
	yyin = fopen("input1.txt", "r");
	yylex();
	
	printf("Total number of numbers in input file: %d\n", integernumbers+floatingnumbers);
	printf("Total number of integer numbers in input file: %d\n", integernumbers);
	printf("Total number of floating-point numbers in input file: %d\n", floatingnumbers);
}