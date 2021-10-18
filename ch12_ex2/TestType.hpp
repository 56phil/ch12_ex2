//
//  testType.hpp
//  testType
//
//  Created by Phil Huffman on 8/28/21.
//

#ifndef testType_hpp
#define testType_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

class TestType {
public:
    char* getID();
    //returns ID
    
    char* getAnswers();
    //returns answer
    
    int getScore(char *, int);
    // returns score of ith test result
    
    char getGrade(char *, int);
    // returns letter grade
    
    TestType(char*, char*);
    // constructor
    
private:
    char *id;
    char *test;
    int score;
    
    void calculateScore(char*, int);
    char calculateGrade(char*, int);
    
};

#endif /* testType_hpp */
