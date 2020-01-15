%{
#include<stdio.h>
%}

%%
\n 	{ return 1; }
[a]+[b]+\n  {  return 0; }
exit  { exit(0); }
. 	;

%%
int yywrap() { return 0; }

int main(){
	int temp;
	while(1) {
		temp = yylex();
		if(!temp) printf("Accepted!! It is of form a^nb^m\n");
		else printf("Rejected!! It is NOT of form a^nb^m\n");
	}	
	return 0;
}