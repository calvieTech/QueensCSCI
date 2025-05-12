//
//  LexicalAnalyzer.cpp
//  assignment1
//
//  Created by Calvin Thang on 10/4/21.
//

#include "LexicalAnalyzer.hpp"
#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "TokenCodes.h"
#include <sstream>
#include <string>
#include <map>

using namespace std;

LexicalAnalyzer::LexicalAnalyzer(ifstream *scf)
{
    sourceCodeFile = scf;
    currentCharPositionNumber = 0;
    line = 1;
    getline(*scf, fileContents);
}

int LexicalAnalyzer::getCurrentCharPositionNumber()
{
    return currentCharPositionNumber;
}

Token* LexicalAnalyzer::getNextToken()
{
    lexStart = currentCharPositionNumber;
    char advance = getNextChar();
    Token *t;
    
    getNonBlank(advance);
    lexLength = 0;
    
    switch(advance) {
        case '+':
            t = addToken(PLUS);
            break;
        case '-':
            t = addToken(MINUS);
            break;
        case '*':
            t = addToken(TIMES);
            break;
        case '/':
            if(isMatch('=')) {
                lexLength++;
                t = addToken(NEQ);
                break;
            } else {
                t = addToken(SLASH);
                break;
            }
        case '<':
            if(isMatch('=')) {
                lexLength++;
                t = addToken(LEQ);
                break;
            } else {
                t = addToken(LSS);
                break;
            }
        case '>':
            if(isMatch('=')) {
                lexLength++;
                t = addToken(GEQ);
                break;
            } else {
                t = addToken(GTR);
                break;
            }
        case '=':
            t = addToken(EQL);
            break;
        case '(':
            t = addToken(LPAREN);
            break;
        case ')':
            t = addToken(RPAREN);
            break;
        case ',':
            t = addToken(COMMA);
            break;
        case ';':
            t = addToken(SEMICOLON);
            break;
        case '\n':
            line++;
            t = addToken(NEWLINE);
            break;
            
        case ':':
            if(isMatch('=')) {
                lexLength++;
                t = addToken(BECOMES);
                break;
            }
            else {
                t = addToken(COLON);
                break;
            }
        case '\0':
            t = addToken(EOI);
            break;
        default:
            if(isDigit(advance)) {
                gatherDigits(advance);
                t = addToken(NUMLIT);
            }
            else if(isAlphabetic(advance)) {
                gatherIdentifiers(advance);
                t = addToken(IDENT);
            }
            else {
                t = addToken(NAL);
            }
    }
  return t;
}

bool LexicalAnalyzer::isAlphabetic(char charInput) {
    return (charInput >= 'a' && charInput <= 'z') ||
            (charInput >= 'A' && charInput <= 'Z') ||
            (charInput == '_');
}

bool LexicalAnalyzer::isDigit(char characterInput) {
    return (characterInput >= '0' && characterInput <= '9');
}

bool LexicalAnalyzer::isAlphaNumeric(char &charInput) {
    return (isAlphabetic(charInput) || isDigit(charInput));
}

bool LexicalAnalyzer::isMatch(char expectedInput) {
    if(isAtEnd()) return false;
    if(fileContents[currentCharPositionNumber] != expectedInput) return false;
    
    currentCharPositionNumber++;
    return true;
}

char LexicalAnalyzer::peekNext() {
    if(currentCharPositionNumber + 1 >= fileContents.length()) {
        return '\0';
    }
    return fileContents.at(currentCharPositionNumber + 1);
}

char LexicalAnalyzer::getCurrentChar() {
    if(isAtEnd()) {
        return '\0';
    }
    return fileContents.at(currentCharPositionNumber);
}

bool LexicalAnalyzer::isAtEnd() {
    return currentCharPositionNumber >= fileContents.length();
}

void LexicalAnalyzer::getNonBlank(char &input) {
    while(isspace(input)) {
        lexStart++;
        lexLength = 0;
        input = getNextChar();
    }
}

void LexicalAnalyzer::gatherDigits(char &digit) {
    int charLength = 0;
    lexLength = 0;
    while(charLength < 10 && isDigit(digit)) {
        lexLength++;
        charLength++;
        digit = getNextChar();
    }
    
    int temp = digit;
    while(isDigit(temp)) {
        temp = getNextChar();
    }
    
}

void LexicalAnalyzer::gatherIdentifiers(char &character) {
    int charLength = 1;
    lexLength = 1;
    character = getNextChar();
    while(lexLength <= 10 && charLength <= 10 && isAlphaNumeric(character) && character != '\0') {
        lexLength++;
        charLength++;
        character = getNextChar();
    }
}

char LexicalAnalyzer::getNextChar() {
    if(isAtEnd()) {
        return '\0';
    }
    return fileContents.at(currentCharPositionNumber++);
}

TokenCodes LexicalAnalyzer::lookup(string lexemeInput) {
    map<string, TokenCodes> keywords;
    keywords["begin"] = BEGINSYM;
    keywords["end"] = ENDSYM;
    keywords["if"] = IFSYM;
    keywords["then"] = THENSYM;
    keywords["else"] = ELSESYM;
    keywords["while"] = WHILESYM;
    keywords["loop"] = LOOPSYM;
    keywords["get"] = GETSYM;
    keywords["put"] = PUTSYM;
    keywords["newline"] = NEWLINE;
    keywords["null"] = NULLSYM;
    keywords["boolean"] = BOOLSYM;
    keywords["integer"] = INTSYM;
    keywords["is"] = ISSYM;
    keywords["procedure"] = PROCSYM;
    keywords["rem"] = REMSYM;
    keywords["true"] = TRUESYM;
    keywords["false"] = FALSESYM;
    keywords["not"] = NOTSYM;
    TokenCodes output;
    
    if(keywords.count(lexemeInput)) {
        output = keywords.at(lexemeInput);
    } else {
        output = IDENT;
        return output;
    }
    
    return output;
}

Token* LexicalAnalyzer::addToken(TokenCodes tokenCodeInput) {
    lexLength++;
    if(tokenCodeInput == NUMLIT) lexLength--;
    if(tokenCodeInput == IDENT) lexLength--;
    string lexeme = fileContents.substr(lexStart, lexLength);
    
    if(tokenCodeInput == NUMLIT) {
        int number = stoi(lexeme);
        Token *p = new Token(tokenCodeInput, lexeme, number);
        listOfTokens.push_back(*p);
        return p;
    }
    
    if(tokenCodeInput == IDENT) {
        if(lookup(lexeme) == IDENT) {
            Token *p = new Token(lookup(lexeme), lexeme, 0);
            listOfTokens.push_back(*p);
            return p;
        } else {
            Token *p = new Token(lookup(lexeme), lexeme, 0);
            listOfTokens.push_back(*p);
            return p;
        }
    }
    Token *p = new Token(tokenCodeInput, lexeme, 0);

    listOfTokens.push_back(*p);
    return p;
}
