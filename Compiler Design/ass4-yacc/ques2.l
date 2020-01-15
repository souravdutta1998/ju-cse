%{
 #include "ques2.tab.h"
 extern int yylval;
%}

%%

[0-9]+ {yylval = atoi(yytext); return id;}
\n { return 0;}
[' '\t]+ {;}
. { return yytext[0];}

%%