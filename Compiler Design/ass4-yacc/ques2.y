%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
int yyerror(char *);
%}

%token  id
%left '+' '-'
%left '*' '/'
%left '(' ')'
%left neg

%%

E1  : E { printf("The resultant value is %d\n", $1);}

E   : E '+' E { $$ = $1 + $3;}
	| E '-' E { $$ = $1 - $3;}
	| E '*' E { $$ = $1 * $3;}
	| E '/' E { $$ = $1 / $3;}
	| '-' E %prec neg{ $$ = -1 * $2;}
	| '(' E ')' { $$ = $2;}
	| id { $$ = $1;}
	;
%%


int main(){
	yyparse();	
	return 0;
}

int yywrap(){}

int yyerror( char* s){
	printf("You entered an invalid expression\n");
	exit(0);
}
