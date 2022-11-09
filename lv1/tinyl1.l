%{
        #include <iostream>
	using namespace std; 
	#include <list>
	#include<string>  
    	#include "symboltable.hh"
	#include "y.tab.h"
  	list<token *> tok;
	int lineno=0;
%}

%%
int     {tok.push_back(new token("int"));cout<<yytext<<endl;yylval.dt=INT; return INTEGER;}
return  {tok.push_back(new token("return"));return RETURN;}
print   {tok.push_back(new token("print"));return PRINT;}
[a-zA-Z][a-zA-Z0-9_]*    {cout<<yytext<<endl;
                        yylval.cval=new string(yytext);
			tok.push_back(new token(*yylval.cval));                     
return ID;}
[0-9]+  {cout<<yytext<<endl;
tok.push_back(new token(yytext)); 
yylval.ival=atoi(yytext);
return NUM;}
[(){}+=;]       {tok.push_back(new token(yytext));cout<<yytext<<endl; return yytext[0];}
[\t ]   {}
\n      {lineno++;}
.      {cout<<"print"<<endl;}
%%


