%{
#include<stdio.h>
int keywords = 0, relop = 0, arithop = 0, assignop = 0, id = 0, num = 0, punc = 0;
%}

%%
[' '\t\n] 	;
"//"[' 'a-zA-Z0-9"+""-""*""/"=<>"."]*  { printf("-----REMOVING THE SINGLELINE COMMENT-----\t\n%s\n",yytext); }
"/*"[' 'a-zA-Z0-9"+""-""*""/"=<>"."\n]*"*/" { printf("-----REMOVING THE MULTILINE COMMENT-----\t\n%s\n",yytext); }
"#include"[' ']?[' '<][a-z]+".h"[' '>] { printf("\theader file\t\t %s\n",yytext); }
else|if|for|int|float|void|return	{keywords++; printf("\tkeyword\t\t\t %s\n",yytext);}
[A-Za-z][A-Za-z0-9]*	{id++; printf("\tidentifier\t\t %s\n",yytext);}
= 	{ assignop++; printf("\tassignment op\t\t %s\n",yytext);}
[<>]	{ relop++; printf("\trelational op\t\t %s\n",yytext);}
"+"|"-"|"*"|"/" 	{ arithop++; printf("\tarithmetic op\t\t %s\n",yytext);}
[;,(){}]		{ punc++; printf("\tpunctuation\t\t %s\n",yytext);}
[+-]?[0-9]+"."[0-9]+ { num++; printf("\tnumber\t\t\t %s\n",yytext);}
[+-]?[0-9]+ { num++; printf("\tnumber\t\t\t %s\n",yytext); }
.	{ printf("\tINVALID\t\t\t %s\n",yytext); }
%%
int yywrap() { return 1; }
int main() {
	printf("----------------------------------------------------------------\n");
	printf("\t\tTYPE \t\t\t TOKEN\n");
	printf("----------------------------------------------------------------\n");
	yyin = fopen("input2.c", "r");
	yylex();
	printf("----------------------------------------------------------------\n");
	printf("Number of keywords in input C file: %d\n", keywords);
	printf("Number of arithmetic operators in input C file: %d\n", arithop);
	printf("Number of relational operators in input C file: %d\n", relop);
	printf("Number of assignment operators in input C file: %d\n", assignop);
	printf("Number of punctuations in input C file: %d\n", punc);
	printf("Number of identifier in input C file: %d\n", id);
	printf("Number of numbers in input C file: %d\n", num);
	
	
	printf("----------------------------------------------------------------\n");
	return 0;
}