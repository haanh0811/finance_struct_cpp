
#ifndef PROJET_LENDER_H
#define PROJET_LENDER_H


#include "Entreprise.h"
#include "Portfolio.h"

class Lender : public Entreprise{
private:
    double totalLent;
    Portfolio* portfolio;

public:
    Lender(std::string name);
    ~Lender();
    Portfolio* getPortfolio();
    void addTotalLent(double amount);
    double getTotalLent() const;
};


#endif //PROJET_LENDER_H
