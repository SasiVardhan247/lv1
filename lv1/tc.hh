#ifndef TC__HH
#define TC__HH

#include <list>
class token{
	string tok;
	public:
		token(string s){
			tok=s;
		}
		void print(ostream &o){
			o<<"Token"<<tok<<endl;
		}
};

#endif

