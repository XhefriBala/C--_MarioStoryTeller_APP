#ifndef ScreenManager_hpp
#define ScreenManager_hpp

#include <iostream>
using namespace std;


class ScreenManager {
public:
   void game();
   void mainGame();
   void nodes();
   char getSelection(string label);
   string stringFromFile(string fileName);
};

#endif /* ScreenManager_hpp */
