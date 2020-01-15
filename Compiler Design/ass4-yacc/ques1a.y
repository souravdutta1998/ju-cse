/*
Design a grammar to recognise a string of the form "aa...abb...b", i.e. any number of "a"s followed by any number of "b"s. Would it be better to use Lex or Yacc to recognise it? 
Lex: 

  a+b+
Yacc e.g.: 

  a_b	: as bs ;
  as	: 'a' | as 'a' ;
  bs	: 'b' | bs 'b' ;
I think the Lex version is much simpler, so I would use Lex. 

*/


%{
#include<stdio.h>
#include<stdlib.h>
int yyerror (char *s);
int yylex();
%}
%token a b

%%

s : as bs ;
as 	: a | as a ;
bs	: b | bs b ;

%%

int yywrap() { return 1; }
int yyerror(char *s) {
	printf("Rejected!! It is NOT of form a^nb^m");
	exit(0);
}
int main() {
	yyparse();
	printf("Accepted!! It is of form a^nb^m\n");
	return 0;
}