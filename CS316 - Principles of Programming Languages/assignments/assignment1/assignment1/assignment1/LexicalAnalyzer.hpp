//
//  LexicalAnalyzer.hpp
//  assignment1
//
//  Created by Calvin Thang on 10/4/21.
//

#ifndef LexicalAnalyzer_hpp
#define LexicalAnalyzer_hpp

#include <fstream>
#include "Token.hpp"
#include "TokenCodes.h"
#include <vector>

class LexicalAnalyzer
{
  private:
    ifstream *sourceCodeFile;
    string fileContents;
    char nextChar;
    int line;
    int currentCharPositionNumber;
    string lexeme;
    vector<Token> listOfTokens;
    bool hasError = false;
    int lexStart;
    int lexLength;
    
    Token* addToken(TokenCodes);
    void increaseLexLength();
    char peekNext();
    bool isMatch(char);
    bool isDigit(char);
    bool isAlphabetic(char);
    bool isAlphaNumeric(char &);
    void gatherDigits(char &);
    void gatherIdentifiers(char &);
    char getCurrentChar();
    void getNonBlank(char &);
    void setFileContents();
    TokenCodes lookup(string);
    char getNextChar();
    bool isAtEnd();
    int getCurrentCharPositionNumber();
    
  public:
    LexicalAnalyzer(ifstream*);
    Token* getNextToken();
};

#endif /* LexicalAnalyzer_hpp */
