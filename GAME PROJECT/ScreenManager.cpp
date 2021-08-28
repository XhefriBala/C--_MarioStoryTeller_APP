#include <iostream>
#include <fstream>
#include <sstream>
#include "ScreenManager.hpp"
#include "StoryNode.hpp"
#include "Exception.h"

using namespace std;

// Screen manager implementation

void ScreenManager::game() {
    
    Exception exc;
    int choice;
    //do while loop for the menu
    do {
        try {
            // menu printed out from txt file
            cout << stringFromFile("ASCII Art/menu.txt");
            
            choice = getSelection("Enter your choice: ");

            //if choice is a num out of that range print out exception file
            if (choice < 1 || choice > 3)
                throw exc;
            //user press 1, then 
            switch (choice) {
            case 1:
                mainGame();
                break;
            //user press 2, then print out instructions from txt file
            case 2:
                cout << stringFromFile("ASCII Art/instructions.txt");
                break;
            case 3:
                //EXIT
                cout << R"(
                                                @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@
                                                @@@                                                                                                         @@@
                                                @@@                       Thanks for playing to this Xhefri Bala's Story Teller Game                        @@@
                                                @@@             Any suggestion to improve the code, please send an email to xhefbala@gmail.com              @@@
                                                @@@                                                                                                         @@@
                                                @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@ @@@
                    )" << endl;
                break;
            }
        } catch (exception & ex) {
            cout << ex.what() << endl;
            system("pause");
        }
    } while (choice != 3);
}


void ScreenManager::mainGame() {

    nodes();
}


//selection from user
char ScreenManager::getSelection(string label) {
    int choice;
    cout << label << ": ";
    cin >> choice;
    return choice;
}

//function to print out the txt files
string ScreenManager::stringFromFile(string fileName) {
    ifstream fin;
    fin.open(fileName);

    stringstream strStream;
    strStream << fin.rdbuf(); //read the file
    string str = strStream.str();

    fin.close();
    return str;
}



//implementation nodes
void ScreenManager::nodes() {
  
     string storyStart = stringFromFile("ASCII Art/MarioWelcome.txt");
    //NODE A
     string choiceStartA = stringFromFile("ASCII Art/choiceA.txt");
     string choiceStartB =  stringFromFile("ASCII Art/choiceB.txt");
     string storyA =stringFromFile("ASCII Art/storyA.txt");
     string choiceAA =stringFromFile("ASCII Art/choiceAA.txt");
     string choiceAB =stringFromFile("ASCII Art/choiceAB.txt");
     string storyAA =stringFromFile("ASCII Art/storyAA.txt");
    // End story
     string storyAB =stringFromFile("ASCII Art/storyAB.txt");
     string choiceABA =stringFromFile("ASCII Art/choiceABA.txt");
     string choiceABB =stringFromFile("ASCII Art/choiceABB.txt");
     string storyABA =stringFromFile("ASCII Art/storyABA.txt");
    // End story
    string storyABB =stringFromFile("ASCII Art/storyABB.txt");
    // End story
    
    
    //NODE B
    string storyB = stringFromFile("ASCII Art/storyB.txt");
    string choiceBA =stringFromFile("ASCII Art/choiceBA.txt");
    string choiceBB =stringFromFile("ASCII Art/choiceBB.txt");
    string storyBA = stringFromFile("ASCII Art/storyBA.txt");
    // End story
    string storyBB =  stringFromFile("ASCII Art/storyBB.txt");
    // End story

    // create StoryNode instances
    StoryNode nodeStart = StoryNode(storyStart);
    StoryNode nodeA = StoryNode(storyA);
    StoryNode nodeB = StoryNode(storyB);
     
    //create Decision instances (two options decision A & B in this case)
    Decision decStartA = Decision('A', choiceStartA, &nodeA);
    Decision decStartB = Decision('B', choiceStartB, &nodeB);
    //add decision to specific story
    nodeStart.addDecision(decStartA);
    nodeStart.addDecision(decStartB);



    // create StoryNode instances
    StoryNode nodeAA = StoryNode(storyAA);
    StoryNode nodeAB = StoryNode(storyAB);
     //create Decision instances
    Decision decAA = Decision('A', choiceAA, &nodeAA);
    Decision decAB = Decision('B', choiceAB, &nodeAB);
      //add decision to specific story
    nodeA.addDecision(decAA);
    nodeA.addDecision(decAB);



    // create StoryNode instances
    StoryNode nodeBA = StoryNode(storyBA);
    StoryNode nodeBB = StoryNode(storyBB);
     //create Decision instances
    Decision decBA = Decision('A', choiceBA, &nodeBA);
    Decision decBB = Decision('B', choiceBB, &nodeBB);
      //add decision to specific story
    nodeB.addDecision(decBA);
    nodeB.addDecision(decBB);



    // create StoryNode instances
    StoryNode nodeABA = StoryNode(storyABA);
    StoryNode nodeABB = StoryNode(storyABB);
     //create Decision instances
    Decision decABA = Decision('A', choiceABA, &nodeABA);
    Decision decABB = Decision('B', choiceABB, &nodeABB);
    //add decision to specific story
    nodeAB.addDecision(decABA);
    nodeAB.addDecision(decABB);

    nodeStart.start();
    }
