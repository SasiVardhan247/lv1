#include<iostream>
using namespace std;
#include "symboltable.hh"
#include "ast.hh"


AssignmentAst::AssignmentAst(Ast *l,Ast *r,int ln){
    lhs=l;
    rhs=r;
    lineNumber=ln;
}

bool AssignmentAst::typeCheckAst(){
    return true;
}

void AssignmentAst::print(ostream & filebuffer){
    lhs->print(filebuffer);
    rhs->print(filebuffer);
    filebuffer<<"Line:\t"<<lineNumber<<endl;
}

PrintAst::PrintAst(Ast* v,int ln){
    var=v;
    lineNumber=ln;
}

void PrintAst::print(ostream & file_buffer){

}

NameAst::NameAst(string & s,SymbolTableEntry & ste,int ln){
    variablesymbolentry=&ste;
    lineNumber=ln;
}

DataType NameAst::getDataType(){
    return nodeDataType;
}

SymbolTableEntry & NameAst::getSymbolEntry(){
    return *variablesymbolentry;
}

void NameAst::print(ostream &filebuffer){
    filebuffer<<"variablesym:\t"<<variablesymbolentry<<endl;
    filebuffer<<"LineNumber:\t"<<lineNumber<<endl;
}

template <class T> NumberAst<T>::NumberAst(T c,DataType dt,int ln){
    constant=c;
    nodeDataType=dt;
    lineNumber=ln;
}

template <class T> DataType NumberAst<T>::getDataType(){
    return nodeDataType;
}

template <class T> void NumberAst<T>::print(ostream &o){
        o<<"Number:\t"<<constant<<endl;
        o<<"DataType:\t"<<nodeDataType<<endl;
        o<<"line:\t"<<lineNumber<<endl;
}

ReturnAst::ReturnAst(int line){
    lineNumber=line;
}

void ReturnAst::print(ostream &o){

}
