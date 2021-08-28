#include <iostream>
#include "StoryNode.hpp"

// StoryNode implementation
StoryNode::StoryNode() {}

StoryNode::StoryNode(string _storyLine) {
    storyLine = _storyLine;
}
//push back put at the end of the array/list
void StoryNode::addDecision(Decision _decision) {
    decisions.push_back(_decision);
}

void StoryNode::start() {
    cout << endl << storyLine << endl;

    //if decisions has anything in the array display "the end" if not show the choices
    if (decisions.empty()) {
        cout << "THE END" << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        
    } else {
        showChoices(); //A or B
        Decision chosenDecision = getChoice(); //get the choice
        StoryNode nextNode = *chosenDecision.nextNode;//that choice get linked with the next node
        nextNode.start(); //start over again
    }
}

void StoryNode::showChoices() {
    cout << endl;

    //loop for 2 times (2 decisions A and B)
    for (Decision d : decisions) {
        cout << d.userChoice << ". " << d.storyChoice << endl;
    }

    cout << endl;
}

Decision StoryNode::getChoice() {
    //when's true will run forever
    while (true) {
        char choice;
        cout << "Your choice: ";
        cin >> choice;

        for (Decision d : decisions) {
            //tolower to convert upercase to lower case, so the program can accept any A or a or b or B
            if (tolower(choice) == tolower(d.userChoice)) {
                return d;
                //if the function hit a return in the for loop all the fucntion stops
            }
        }
    }
}


// Decision implementation
Decision::Decision(char _userChoice, string _storyChoice, StoryNode* _nextNode) {
    userChoice = _userChoice;
    storyChoice = _storyChoice;
    nextNode = _nextNode;
}
