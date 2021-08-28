#ifndef Exception_h
#define Exception_h

#include <exception>

using namespace std;

class Exception : public exception
{
    virtual const char* what() const throw()
    {
        return "Wrong choice, try again please :)";
    }
};
#endif /* Exception_h */
