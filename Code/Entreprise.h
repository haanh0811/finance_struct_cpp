//
// Created by Julien on 28/05/2024.
//

#ifndef PROJET_ENTREPRISE_H
#define PROJET_ENTREPRISE_H


#include <string>

class Entreprise {
private:
    std::string name;


public:
    Entreprise(std::string &name);
    Entreprise();

    std::string getName();
    void setName(std::string name);

public:

};


#endif //PROJET_ENTREPRISE_H
