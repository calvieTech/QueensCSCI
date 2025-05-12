//
//  Token.hpp
//  assignment1
//
//  Created by Calvin Thang on 10/4/21.
//

#ifndef Token_hpp
#define Token_hpp

#include <iostream>
#include <string>
#include "TokenCodes.h"

using namespace std;

class Token
{
  private:
    int lexemeNumber;
    string lexemeString;
    TokenCodes tokenCode;

  public:
    Token();
    Token(TokenCodes, string, int);
    int getLexemeNumber();
    void setLexemeNumber(int);
    string getLexemeString();
    void setLexemeString(string);
    TokenCodes getTokenCode();
    void setTokenCode(TokenCodes);
    friend ostream& operator<<(ostream& os, const Token& t);
};

#endif /* Token_hpp */
