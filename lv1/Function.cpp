#include<iostream>
using namespace std;
#include "symboltable.hh"
#include "ast.hh"
#include "Function.hh"

Function::Function(DataType dt,string s,int l)
{
        name=s;
        returnType=dt;
        lineno=l;
}
Function::Function(){
	returnType=INT;
	name="";
	lineno=0;
}

Function::~Function()
{
}


string Function::getFunctionName()
{
        return name;
}


void Function::setLocalList(SymbolTable &st)
{
        localSymbolTable=st;
}


SymbolTable Function::getLocalList()
{
        return localSymbolTable;
}


void Function::setAstList(list<Ast *> &sa)
{
        statementList=sa;
}


DataType Function::getReturnType()
{
        return returnType;
}


void Function::setReturnType(DataType dt)
{
        returnType=dt;
}


SymbolTableEntry & Function::getSymbolTableEntry(string vn)
{
    return localSymbolTable.getSymbolTableEntry(vn);
}


void Function::print(ostream &f)
{
	f<<"DATATYPE:"<<((returnType)==INT?"INT ":" ")<<" NAME: "<<name;
	f<<"LINENO: "<<lineno<<endl;
	f<<"Local Declarations"<<endl;
	printSymbolTable(f);
}


void Function::printSymbolTable(ostream &f)
{
	localSymbolTable.print(f);
}

// void Function::generateTargetCode(){
// }
// void Function::printPrologue(ostream & file_buffer)
// {
// 	stringstream prologue;

// 	prologue << "\n\
// 	.text \t\t\t# The .text assembler directive indicates\n\
// 	.globl " << name << "\t\t# The following is the code (as oppose to data)\n";

// 	prologue << name << ":\t\t\t\t# .globl makes main know to the \n\t\t\t\t# outside of the program.\n\
// # Prologue begins \n\
// 	sw $ra, 0($sp)\t\t# Save the return address\n\
// 	sw $fp, -4($sp)\t\t# Save the frame pointer\n\
// 	sub $fp, $sp, 8\t\t# Update the frame pointer\n";

// 	int size = localSymbolTable.size();
// 	size = -size;
// 	prologue << "\n\tsub $sp, $sp, " << (size + 8) << "\t\t# Make space for the locals\n";
// 	prologue << "# Prologue ends\n\n";

// 	file_buffer << prologue.str();
// }

// void Function::printEpilogue(ostream & file_buffer)
// {
// 	stringstream epilogue;

// 	int size = localSymbolTable.size();
// 	size = -size;

// 	epilogue << "\n# Epilogue Begins\nepilogue_" << name << ":\n\tadd $sp, $sp, " << (size+8) << "\n";
// 	epilogue << "\tlw $fp, -4($sp)  \n\tlw $ra, 0($sp)   \n\t";

// 	epilogue << "jr  $31\t\t# Jump back to the called procedure\n# Epilogue Ends\n\n";

// 	file_buffer << epilogue.str();
// }

// void Function::printTargetCode(ostream & file_buffer)
// {
// 	printPrologue(file_buffer);

// 	list<Instruction *>::iterator i;
// 	for (i = instList.begin(); i != instList.end(); i++)
// 		(*i)->print(file_buffer);

// 	print_epilogue(file_buffer);
// }



