#include<iostream>
using namespace std;
#include "ast.hh"
#include "Function.hh"
#include "symboltable.hh"
#include "program.hh"
#include<string.h>

Program::Program(){}
Program::~Program(){}
Function * Program::getFunctionDetails(string str)
{
        if(FunctionMap.find(str)!=FunctionMap.end())    return FunctionMap[str];
        return NULL;
}


void Program::addFunctionDetails(string str, Function *f)
{
        FunctionMap[str]=f;
}

void Program::setFunctionMap(map<string, Function *> &sfm)
{
        FunctionMap=sfm;
}

void Program::setGlobalTable(SymbolTable &gs)
{
        globalSymbolTable=gs;
}

SymbolTableEntry & Program::getSymbolTableEntry(string vn)
{
        return globalSymbolTable.getSymbolTableEntry(vn);
}

void Program::printSymbolTable(ostream &o)
{
        globalSymbolTable.print(o);
}

void Program::print(ostream &o){
        o<<"Global Declarations : "<<endl;
	printSymbolTable(o);
	o<<"Program"<<endl;
	for(auto i=FunctionMap.begin();i!=FunctionMap.end();i++){
		(i->second)->print(o);
	}
}

Function *Program:: getMainFunction(){
        return getFunctionDetails("main");
}


bool Program::variableFunctionNameCheck(string str)
{
   if(FunctionMap.find(str)!=FunctionMap.end()) return true;
   return false;
}

bool Program::variableInSymbolTableCheck(string str)
{
        if(globalSymbolTable.variableInSymbolListCheck(str))    return true;
        return false;
}


// void program::generateTargetCode(){
// }

// void program::printTargetCode(){
// }


