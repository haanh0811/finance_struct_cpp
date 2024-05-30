//
// Created by Julien on 28/05/2024.
//

#ifndef PROJET_LENDER_H
#define PROJET_LENDER_H


#include "Entreprise.h"
#include "Portfolio.h"

class Lender : public Entreprise{
private:
    Portfolio* portfolio;

public:
    Lender(std::string name);
    Portfolio* getPortfolio();

    void addInterest(double d);
};


#endif //PROJET_LENDER_H
