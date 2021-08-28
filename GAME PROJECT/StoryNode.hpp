#include <iostream>
#include <vector>
using namespace std;

class StoryNode;
class Decision;

//Represent every story node when user has to make a choice to move on
class StoryNode {
private:
    //The main story line of that node
    string storyLine;
    //the decision the player has to make to move to the next node
    vector<Decision> decisions;
    //display all the choices of the node
    void showChoices();
    //Accept user choice
    Decision getChoice();

public:
    // Constructors
    // Default Constructors
    StoryNode();
    StoryNode(string _storyLine);
    //add decision to the node
    void addDecision(Decision _decision);
    //show the story line and display the decison
    void start();//to run the story
};

class Decision {
public:
    //the letter represent the choice (e.g. A,B)
    char userChoice;
    //The choice content
    string storyChoice;
    //the next story node asscociate with the choice
    StoryNode* nextNode;

    //Constructors
    Decision(char, string, StoryNode*);
};
