%{
        #include <iostream>
        using namespace std;
	#include <string.h>
	#include "symboltable.hh"
	#include "Function.hh"
	#include "ast.hh"
	#include<map>
	#include "program.hh"
	extern FILE* yyin;
        extern int yylex();
	extern list<token *> tok;
	extern int lineno;
	void yyerror(char *);
	SymbolTable *gst=new SymbolTable();
%}
%union{
       string *cval;
        int ival;
	SymbolTableEntry *ste;
	Ast *a;
	Program *pr;
	Function *f;
	list<Ast*> *la;
	DataType dt;
};
%start program
%token <dt> INTEGER
%token RETURN
%token PRINT
%token <cval> ID
%token <ival> NUM

%type <ste> vardecl
%type <a> assignment_stmt return_stmt print_stmt
%type <f> main_function
%type <la> stmt_list
%type <pr> program

%%
program:main_function {$$=new Program();$$->addFunctionDetails($1->getFunctionName(),$1);
       cout<<"Accepted"<<endl;}
;
main_function:INTEGER ID '(' ')' '{' optional_local_var_decl stmt_list return_stmt '}' {$$=new Function($1,*$2,lineno);
	$$->setAstList(*$7);	     
//	$$->print(cout);
cout<<*$2<<endl;}
;
stmt_list:assignment_stmt {
	 $$=new list<Ast*>();
	 ($$)->push_back($1);
}
|print_stmt {$$=new list<Ast *>();
($$)->push_back($1);}
|assignment_stmt stmt_list {
	($2)->push_back($1);
	$$=$2;
}
|print_stmt stmt_list   {
	($2)->push_back($1);
	$$=$2;
}
;
print_stmt:PRINT ID ';' {$$=new PrintAst(new NameAst(*$2,gst->getSymbolTableEntry(*$2),lineno),lineno);
//	  $$->print(cout);
	
};
assignment_stmt:ID '=' ID ';' {$$=new AssignmentAst(new NameAst(*$1,gst->getSymbolTableEntry(*$1),lineno),new NameAst(*$3,gst->getSymbolTableEntry(*$3),lineno),lineno);
//	       $$->print(cout);
//	       cout<<*$1<<"="<<*$3<<endl;
}
|ID '=' NUM ';'     {DataType dt=INT;
$$=new AssignmentAst(new NameAst(*$1,gst->getSymbolTableEntry(*$1),lineno),new NumberAst<int>($3,dt,lineno),lineno);
//$$->print(cout);
//cout<<*$1<<"="<<$3<<endl;
}
return_stmt:RETURN NUM ';'       {$$=new ReturnAst(lineno);
//	   $$->print(cout);
}	
optional_local_var_decl: |vardecl optional_local_var_decl {}
;
vardecl:INTEGER ID ';' {
       gst->pushSymbol(new SymbolTableEntry(*$2,$1,lineno));
			$$=&(gst->getSymbolTableEntry(*$2));       
};
%%

void yyerror(char *s){
	cout<<s<<endl;
}

int main(int argc,char *argv[]){
	yyin=fopen(argv[1],"r");
        yyparse();
	list <token *>::iterator it;
	for(it=tok.begin();it!=tok.end();++it){
		(*it)->print(cout);
	}
	gst->print(cout);
	return 0;	
}
