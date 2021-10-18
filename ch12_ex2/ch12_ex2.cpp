//
//  main.cpp
//  ch12_ex2
//
//  Created by Phil Huffman on 8/28/21.
//
// CH12_EX2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iomanip>
#include <iostream>
#include <vector>
#include "TestType.hpp"

using namespace std;
int main() {
    string noOfQuestions;
    int questionCountIn(0);
    
    while (questionCountIn <= 0) {
        try {
            cout << "Enter number of exam questions: ";
            cin >> noOfQuestions;
            cout << endl;
            questionCountIn = stoi(noOfQuestions);
            if (questionCountIn <= 0) {
                throw invalid_argument("Positive integer required.");
            }
        }
        catch(invalid_argument) {
            cerr << "Positive integer required." << endl;
        }
    }

    char *keyPtr(nullptr);
    bool hasKey(false);
    int keySize(0);
    vector<TestType>tests;
    static const char fn[] = "/Users/prh/Keepers/code/cpp/CSIS 223/ch12/Notes/Ch12_Ex2Data.txt";
    FILE *file = fopen(fn, "r");
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buff = new char[fsize + 1];
    memset(buff, 0, fsize + 1);
    fread(buff, 1, fsize, file);
    fclose(file);
    char *buffPtr(buff);
    char *workPtr(buff);
    char *buffEnd(buff + fsize);
    
    while (workPtr) {
        workPtr = strchr(buffPtr, '\n');
        if (workPtr) {
            *workPtr = '\0';
            workPtr += 9;
            if (*workPtr == ' ') {
                *workPtr = '\0';
            }
            buffPtr = workPtr + 1;
        }
    }
    
    buffPtr = buff;
    workPtr = buff;
    while (buffPtr < buffEnd) {
        if(hasKey) {
            workPtr = buffPtr + strlen(buffPtr) + 1;
            TestType tmp(buffPtr, workPtr);
            tests.emplace_back(tmp);
        } else {
            keyPtr = workPtr;
            keySize = static_cast<int>(strlen(keyPtr));
            keySize = keySize > questionCountIn ? questionCountIn : keySize;
            hasKey = true;
        }
        buffPtr = workPtr + strlen(workPtr) + 1;
    }
    
    cout << "questions: " << keySize
    << "\nkey: " << keyPtr << "\n\n";
    
    for (auto test : tests) {
        cout << left << setw(9) << test.getID()
        << left << setw(keySize + 1) << test.getAnswers()
        << setw(3) << test.getScore(keyPtr, keySize)
        << setw(2) << test.getGrade(keyPtr, keySize) << "\n";
    }
    
    delete [] keyPtr;
    
    return 0;
}
