#include <iostream>
#include "CharStack.hpp"

string exercicio2(string s){
    char ch;
    CharStack p( s.length() );
    string res = "";
    
    for(int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
            if(c == '.' || c == ' '){
                while( p.pop(ch) ) res += ch;
                res += c;
            }
        else if ( !p.push(c) ) cerr << "ERRO!"<<endl;
    }

     while( p.pop(ch) ) res += ch;
    
    return res;
}

int main(){
    string s = "ETSE OICICREXE E OTIUM LICAF.";
        cout << s <<endl;
        cout << exercicio2(s)<<endl;
    return 0;
}