#ifndef DATE_H
#define DATE_H


#include <iostream>

class Date {
private:
    static int time;
public:
    static int getTime();
    static void advance();
};




#endif
