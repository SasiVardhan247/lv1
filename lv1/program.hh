
#ifndef PROGRAM_HH
#define PROGRAM_HH
class Program;
extern Program programObject;

class Program
{
	SymbolTable globalSymbolTable;
	map<string, Function *> FunctionMap;

public:
	Program();
	~Program();
	Function * getFunctionDetails(string );
	void addFunctionDetails(string , Function *);
	void setFunctionMap(map<string, Function *> &);
	void setGlobalTable(SymbolTable &);
	SymbolTableEntry & getSymbolTableEntry(string);
	void printSymbolTable(ostream &);
	void print(ostream &);
	Function * getMainFunction();
	bool variableFunctionNameCheck(string);
	bool variableInSymbolTableCheck(string);

	//functions added for code generation

	// void generateTargetCode();
	// void printTargetCode();
};

#endif

