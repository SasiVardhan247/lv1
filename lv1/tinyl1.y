%{
        #include <iostream>
        using namespace std;
	#include <string>
	#include "symboltable.hh"
	#include "ast.hh"
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
	DataType dt;
}
%start program
%token <dt> INTEGER
%token RETURN
%token PRINT
%token <cval> ID
%token <ival> NUM

%type <ste> vardecl
%type <a> assignment_stmt 
%%
program:main_function {cout<<"Stop"<<endl;}
;
main_function:INTEGER ID '(' ')' '{' optional_local_var_decl stmt_list return_stmt '}' {cout<<*$2<<endl;}
;
stmt_list:assignment_stmt {}
|print_stmt {}
|assignment_stmt stmt_list {}
|print_stmt stmt_list   {}
;
print_stmt:PRINT ID ';' {};
assignment_stmt:ID '=' ID ';' {$$=new AssignmentAst(new NameAst(*$1,gst->getSymbolTableEntry(*$1),lineno),new NameAst(*$3,gst->getSymbolTableEntry(*$3),lineno),lineno);
	       $$->print(cout);
	       cout<<*$1<<"="<<*$3<<endl;}
|ID '=' NUM ';'     {DataType dt=INT;
$$=new AssignmentAst(new NameAst(*$1,gst->getSymbolTableEntry(*$1),lineno),new NumberAst<int>($3,dt,lineno),lineno);
$$->print(cout);
cout<<*$1<<"="<<$3<<endl;}
return_stmt:RETURN NUM ';'       {cout<<"0"<<endl;}	
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
	
}
