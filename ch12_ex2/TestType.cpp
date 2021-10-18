//
//  testType.cpp
//  testType
//
//  Created by Phil Huffman on 8/28/21.
//

#include "TestType.hpp"

char* TestType::getID() {
    return id;
}

char* TestType::getAnswers() {
    return test;
}

int TestType::getScore(char *keyPtr, int keySize) {
    calculateScore(keyPtr, keySize);
    return score;
}

char TestType::getGrade(char *keyPtr, int keySize) {
    return calculateGrade(keyPtr, keySize);
}

void TestType::calculateScore(char *keyPtr, int keySize) {
    score = 0;
    char *testPtr(test);
    while (*testPtr && *keyPtr) {
        if (*testPtr != ' ') {
            if (*testPtr == *keyPtr) {
                score += 2;
            } else {
                score--;
            }
        }
        testPtr++;
        keyPtr++;
    }
}

char TestType::calculateGrade(char *keyPtr, int keySize) {
    if (score == 0) {
        calculateScore(keyPtr, keySize);
    }
    
    switch (static_cast<int>(TestType::score / 40.0 * 10.0)) {
        case 6:
            return 'D';
        case 7:
            return 'C';
        case 8:
            return 'B';
        case 9:
        case 10:
            return 'A';
        default:
            return 'F';
    }
}

TestType::TestType(char *_id, char *_test) {
    score = 0;
    id = _id;
    test = _test;
}
// constructor
