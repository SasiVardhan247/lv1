#include<iostream>
using namespace std;
#include "symboltable.hh"
#include "ast.hh"


Ast::Ast(){}
Ast::~Ast(){}

DataType Ast::getDataType(){
        return nodeDataType;
}

bool Ast::typeCheckAst(){
        if(nodeDataType==INT)   return true;
        return false;
}

void Ast::print(ostream &o){
        o<<"NodeDataType:\t"<<nodeDataType<<endl;
}

AssignmentAst::AssignmentAst(Ast *l,Ast *r,int ln){
    lhs=l;
    rhs=r;
    lineNumber=ln;
}

AssignmentAst::~AssignmentAst(){}

bool AssignmentAst::typeCheckAst(){
    return true;
}

void AssignmentAst::print(ostream & o){
    // lhs->print(filebuffer);
    // rhs->print(filebuffer);
    // filebuffer<<"Line:\t"<<lineNumber<<endl;
    o<<"Asgn:"<<endl;
	o<<"\tLHS "<<"( ";
	lhs->print(o);
	o<<" )"<<endl;
	o<<"\tRHS "<<"( ";
	rhs->print(o);
	o<<" )"<<endl;
}

PrintAst::PrintAst(Ast* v,int ln){
    var=v;
    lineNumber=ln;
}

PrintAst::~PrintAst(){}

void PrintAst::print(ostream & file_buffer){
}

NameAst::NameAst(string & s,SymbolTableEntry & ste,int ln){
    variablesymbolentry=&ste;
    lineNumber=ln;
}

NameAst::~NameAst(){}

DataType NameAst::getDataType(){
    return variablesymbolentry->getDataType();
}

SymbolTableEntry & NameAst::getSymbolEntry(){
    return *variablesymbolentry;
}

void NameAst::print(ostream &filebuffer){
    filebuffer<<"variablesym:\t"<<variablesymbolentry->getVariableName();
}

template <class T> NumberAst<T>::NumberAst(T c,DataType dt,int ln){
    constant=c;
    nodeDataType=dt;
    lineNumber=ln;
}

template <class T> NumberAst<T>::~NumberAst(){}

template <class T> DataType NumberAst<T>::getDataType(){
    return nodeDataType;
}

template <class T> void NumberAst<T>::print(ostream &o){
        o<<"Number:\t"<<constant;
}

template class NumberAst<int>;

ReturnAst::ReturnAst(int line){
    lineNumber=line;
}

void ReturnAst::print(ostream &o){

}

