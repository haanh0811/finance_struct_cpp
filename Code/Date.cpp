#include "Date.h"

int Date::time = 0;

int Date::getTime() {
    return time;
}

void Date::advance(){
    time++;
}
