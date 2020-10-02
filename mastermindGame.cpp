//
// Created by cohen on 5/13/2020.
// Changelog
// 5/13/2020    - separate class source files code.cpp, response.cpp and mastermind.cpp were unified
//              - added large comment headers to help separate classes visually
//              - changed checkIncorrect function to now remove already found matches
//              - improved comments
//              - completed the playGame() function

/**********************************************************************************************************************/
#include "mastermindGame.h"
/**********************************************************************************************************************/

/**********************************************************************************************************************/
//                    _
//     ___  ___    __| |  ___
//    / __|/ _ \  / _` | / _ \
//   | (__| (_) || (_| ||  __/
//    \___|\___/  \__,_| \___|
//
code::code() : codeVect(4){// constructor called with no inputs generates a random 4 digit code stores into codeVect
    srand(time(nullptr));// seed random number generation
    for(int i = 0; i<=3; i++){
        codeVect[i] = rand() % 6;// fill codeVect with random integers
    }
}
code::code(int in0, int in1, int in2, int in3) {// constructor call with 4 int inputs stores those inputs into codeVect
    codeVect = {in0, in1, in2, in3};// fill codeVect with specified integers
}
int code::checkCorrect(code guess){// returns # of correct digits in the correct location
    int matches = 0;// starting count of matches
    for(int i =0; i<=3; i++){// iterate through both vectors
        if (guess.codeVect[i] == codeVect[i]){// compare the digit at the same position
            matches++;// same number at same position then increase matches 1
        }
    }
    return matches;
}
int code::checkIncorrect(code guess){// returns # of correct digits in the incorrect location
    int matches = 0;// starting count of matches
    vector<int> tempCode = codeVect;// create a copy of the secret code
    for(int i =0; i<=3; i++){// iterator for the guess vector
        for(int j=0; j<tempCode.size(); j++){// iterator for the secret code vector
            if (guess.codeVect[i] == tempCode[j]){// same number at any position
                matches++;
                tempCode.erase(tempCode.begin() + j);// remove the matching digit from the secret code copy
                break;// stop searching for matches for that position of guess code
            }
        }
    }
    return matches - checkCorrect(guess);// return the difference of half matches and full matches
}
vector<int> code::codePass(){// passes the private codeVect from this class
    return codeVect;
}
/**********************************************************************************************************************/

/**********************************************************************************************************************/
//    _ __  ___  ___  _ __    ___   _ __   ___   ___
//   | '__|/ _ \/ __|| '_ \  / _ \ | '_ \ / __| / _ \
//   | |  |  __/\__ \| |_) || (_) || | | |\__ \|  __/
//   |_|   \___||___/| .__/  \___/ |_| |_||___/ \___|
//                   |_|
response::response(){// constructor called w/o input sets variables to NULL
    correct = NULL;
    incorrect = NULL;
}
response::response(int in1, int in2){// constructor called w/ input sets variables to inputted values
    correct = in1;
    incorrect = in2;
}
bool response::checkWin(){// returns true if 4 correct digits in the correct location
    return correct == 4;
}
void response::printResponse(){// outputs codemakers response of correct and incorrect to the console
    printf("codemaker answer (%d,%d)\n\n", correct, incorrect);
}
/**********************************************************************************************************************/

/**********************************************************************************************************************/
//                           _                          _             _
//    _ __ ___    __ _  ___ | |_  ___  _ __  _ __ ___  (_) _ __    __| |
//   | '_ ` _ \  / _` |/ __|| __|/ _ \| '__|| '_ ` _ \ | || '_ \  / _` |
//   | | | | | || (_| |\__ \| |_|  __/| |   | | | | | || || | | || (_| |
//   |_| |_| |_| \__,_||___/ \__|\___||_|   |_| |_| |_||_||_| |_| \__,_|
//
void mastermind::printSecretCode(){// prints the masterCode vector(secret code) to the console
    vector<int> temp = masterCode.codePass();
    for(int i = 0; i<=3; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
}
code mastermind::humanGuess(){// gets 4 ints from user and constructs a code object with users inputs
    int in0, in1, in2, in3;
    bool valid = false;
    while (!valid){// request input until valid input supplied
        cout << "Enter four inputs between 0 to 5 separated by a space:";cin >> in0 >> in1 >> in2 >> in3;
        vector<int> tempVect = {in0, in1, in2, in3};// assemble inputs into temporary vector for iteration
        for(int i=0; i<=3; i++){// iterate through temporary vector
            if(tempVect[i]<0 || tempVect[i]>5){// check that no input is less than zero or greater than 5
                cout << "invalid input" << endl;// inform the user
                break;// stop looking for invalid inputs
            }else{// otherwise give the loop an exit
                valid = true;
            }
        }
    }
    return code(in0,in1,in2,in3);
}
response mastermind::getResponse(code guess, code masterCode){// pass guess and secret code and return a response
    int correct, incorrect;
    correct = masterCode.checkCorrect(guess);// record # correct digit correct position
    incorrect = masterCode.checkIncorrect(guess);// record # correct digit incorrect position
    return {correct, incorrect};

}
bool mastermind::isSolved(response in1){// forwards boolean output from checkWin function
    return in1.checkWin();
}
void mastermind::playGame(){// handles the mechanics of playing the game
    //masterCode = code(3,2,3,3);// assign custom secret code for testing
    printSecretCode();// print the secret code to the console
    for(int i=1; i<=10; i++){// iterate for 10 rounds
        code guess = humanGuess();// request user input and save into code object
        response response = getResponse(guess, masterCode);// create a response to current guess vs secret code
        response.printResponse();// print codemakers response
        bool expression = isSolved(response);// record if user guess was completely correct
        if(expression){// users guess was completely correct
            cout << "Correct you win!" << endl;// inform the user they have won
            break;
        }
    }
}
/**********************************************************************************************************************/

