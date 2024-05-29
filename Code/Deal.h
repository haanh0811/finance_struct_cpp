#ifndef PROJET_DEAL_H
#define PROJET_DEAL_H


#include <string>
#include "Date.h"
#include "Lender.h"


class Deal {
private:
    std::string numeroContrat;
    std::string agent;
    Lender* pool[5];
    std::string borrower;
    double montantProjet;
    double montantADebloquer;
    std::string devise;
    int signatureContrat;
    int finContrat;
    std::string status;
public:
    Deal(std::string numContrat, std::string agentName, Lender* b[5], std::string borrowerName, double montant, std::string devise, int signature, int fin);

};


#endif //PROJET_DEAL_H
