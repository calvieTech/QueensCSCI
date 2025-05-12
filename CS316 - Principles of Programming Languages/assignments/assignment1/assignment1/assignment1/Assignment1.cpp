//
//  Assignment1.cpp
//  assignment1
//
//  Created by Calvin Thang on 10/4/21.
//

#include <stdio.h>
#include <fstream>
#include <iostream>

#include "LexicalAnalyzer.hpp"
#include "Token.hpp"
#include "TokenCodes.h"

int main(int argc, char *argv[])
{
  ifstream sourceCodeFile;
  LexicalAnalyzer *la;
  Token *nextToken;
  TokenCodes tc;

  sourceCodeFile.open(argv[1], ifstream::in);
  if  (sourceCodeFile.is_open())
  {
    la = new LexicalAnalyzer(&sourceCodeFile);
    do
    {
      nextToken = la->getNextToken();
      cout << *nextToken << endl;
      tc = nextToken->getTokenCode();
      delete nextToken;
    } while (tc != EOI);
    delete la;
  }
  else
    printf("ERROR - cannot open input file \n");

  return 0;
}
