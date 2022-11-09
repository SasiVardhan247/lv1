#include <iostream>
#include "symboltable.hh"
#include <list>
using namespace std;

void SymbolTable::print(ostream &f)
{
	list<SymbolTableEntry *>::iterator it;
 	for(it=varTable.begin();it!=varTable.end();++it){
                f<<"Variable Name:";f.width(8);
                f<<(*it)->getVariableName()<<"\t\t";
                f<<"DataType:";
                if((*it)->getDataType()==0){
			f<<"INT \t";
		}
                f<<"Line Number:";
                f<<(*it)->getLineNumber()<<endl;
        }
}

TableScope SymbolTable::getTableScope()
{
        return scope;
}

void SymbolTable::setTableScope(TableScope a)
{
        scope=a;
}

void SymbolTable::pushSymbol(SymbolTableEntry *se)
{
        varTable.push_back(se);
}

bool SymbolTable::variableInSymbolListCheck(string vn)
{
        list<SymbolTableEntry*>::iterator litr;
        for(litr=varTable.begin();litr!=varTable.end();litr++)
        {
                  if((*litr)->getVariableName()==vn)
                {
                        return true;
                }

        }
        return false;
}

int SymbolTableEntry::getLineNumber()
{
        return lineNumber;
}

void SymbolTableEntry::setSymbolScope(TableScope sp)
{
        scope=sp;
}

DataType SymbolTableEntry::getDataType()
{
        return variabledatatype;
}


void SymbolTableEntry::setDataType(DataType d)
{
        variabledatatype=d;
}

string SymbolTableEntry::getVariableName()
{
        return variablename;
}

SymbolTableEntry::SymbolTableEntry()
{

}

SymbolTableEntry::SymbolTableEntry(string &s,DataType d,int n)
{
        variabledatatype=d;
	variablename=s;
	lineNumber=n;
}

SymbolTableEntry::~SymbolTableEntry()
{

}

SymbolTable::SymbolTable(){}
SymbolTable::~SymbolTable(){}

SymbolTableEntry& SymbolTable::getSymbolTableEntry(string variablename){
	SymbolTableEntry  *x=NULL;
	for(auto it=varTable.begin();it!=varTable.end();++it){
		if((*it)->getVariableName()==variablename){
			x=*it;
			return **it;
		}
	}
	return *x;
}

token::token(string s){
        tok=s;
}

void token::print(ostream &o){
        o<<"Token:      \t"<<tok<<endl;
}
