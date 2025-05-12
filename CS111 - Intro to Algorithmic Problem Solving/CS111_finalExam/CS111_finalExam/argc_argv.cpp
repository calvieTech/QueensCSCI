//
//  argc_argv.cpp
//  CS111_finalExam
//
//  Created by Calvin Thang on 8/26/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "number of arguments: " << argc << endl;
    for (int i =0; i < argc; ++i) cout << argv[i] << endl;
    return 0;
    
    
    
}
