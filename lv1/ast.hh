#ifndef AST_HH
#define AST_HH

/*
typedef enum
{
	INT
} DataType;
*/
class Ast
{
protected:
	DataType nodeDataType;
	int lineNumber;

public:
	Ast();
	~Ast();

	virtual DataType getDataType();
	virtual bool typeCheckAst();
	virtual void print(ostream &) = 0;

	//functions added for code generation
	// virtual TargetCodeForAst & generateTargetCode();
};

class AssignmentAst:public Ast
{
	Ast * lhs;
	Ast * rhs;

public:
	AssignmentAst(Ast *, Ast *, int);
	~AssignmentAst();
	bool typeCheckAst();
	void print(ostream & filebuffer);

	//functions added for code generation
	// virtual TargetCodeForAst & generateTargetCode();
};

class PrintAst:public Ast
{
     Ast *var;
public:
	PrintAst(Ast *, int);
	~PrintAst();
	void print(ostream & file_buffer);

	//functions added for code generation
	// virtual TargetCodeForAst & generateTargetCode();
};


class NameAst:public Ast
{
	SymbolTableEntry * variablesymbolentry;

public:
	NameAst(string &,SymbolTableEntry &, int );
	~NameAst();
	DataType getDataType();
	SymbolTableEntry & getSymbolEntry();
	void print(ostream & filebuffer);

	//functions added for code generation
	// virtual TargetCodeForAst & generateTargetCode();

};

template <class T>
class NumberAst:public Ast
{
	T constant;

public:
	NumberAst(T, DataType, int);
	~NumberAst();

	DataType getDataType();

	void print(ostream &);

	//functions added for code generation
	// virtual TargetCodeForAst & generateTargetCode();


};

class ReturnAst:public Ast
{

public:
	ReturnAst(int line);
	~ReturnAst();

	void print(ostream &);
	//functions added for code generation
	// virtual TargetCodeForAst & generateTargetCode();

};

#endif

