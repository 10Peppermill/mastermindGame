//
// Created by cohen on 5/13/2020.
// Changelog
// 5/13/2020    - separated class header files code.h, response.h and mastermind.h were unified into a single header file
//              - added large comment headers to help separate classes visually
//              - improved comments

#ifndef MASTERMINDGAME_MASTERMINDGAME_H
#define MASTERMINDGAME_MASTERMINDGAME_H

/**********************************************************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/**********************************************************************************************************************/

/**********************************************************************************************************************/
//                    _
//     ___  ___    __| |  ___
//    / __|/ _ \  / _` | / _ \
//   | (__| (_) || (_| ||  __/
//    \___|\___/  \__,_| \___|
class code {
private:
    vector<int> codeVect;// 4 digit code (either a secret code or a guess)
public:
    code();
    code(int in0, int in1, int in2, int in3);
    int checkCorrect(code);// passed a guess obj & returns # correct digits in correct location
    int checkIncorrect(code);// passed a guess obj & returns # correct digits in incorrect location
    vector<int> codePass();// passes private codeVect to the printSecretCode function in mastermind class

};
/**********************************************************************************************************************/

/**********************************************************************************************************************/
//    _ __  ___  ___  _ __    ___   _ __   ___   ___
//   | '__|/ _ \/ __|| '_ \  / _ \ | '_ \ / __| / _ \
//   | |  |  __/\__ \| |_) || (_) || | | |\__ \|  __/
//   |_|   \___||___/| .__/  \___/ |_| |_||___/ \___|
//                   |_|
class response {
private:
    int correct;//# of correct digits in the correct location
    int incorrect;//# of correct digits in the incorrect location
public:
    response();// constructor called w/o input
    response(int, int);// constructor called w/ two int inputs
    bool checkWin();// compares response and returns true if codes are equal
    void printResponse();// outputs codemakers response of correct and incorrect to the console
};
/**********************************************************************************************************************/

/**********************************************************************************************************************/
//                           _                          _             _
//    _ __ ___    __ _  ___ | |_  ___  _ __  _ __ ___  (_) _ __    __| |
//   | '_ ` _ \  / _` |/ __|| __|/ _ \| '__|| '_ ` _ \ | || '_ \  / _` |
//   | | | | | || (_| |\__ \| |_|  __/| |   | | | | | || || | | || (_| |
//   |_| |_| |_| \__,_||___/ \__|\___||_|   |_| |_| |_||_||_| |_| \__,_|
class mastermind {
private:
    code masterCode;// stores the secret code

public:
    void printSecretCode();// prints the secret code to the console
    code humanGuess();// request guess input from the user
    response getResponse(code, code);// pass guess and secret code and return a response
    bool isSolved(response);// check if user guess was completely correct
    void playGame();// handles the mechanics of playing the game
};
/**********************************************************************************************************************/


#endif //MASTERMINDGAME_MASTERMINDGAME_H
