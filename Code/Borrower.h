#ifndef PROJET_BORROWER_H
#define PROJET_BORROWER_H


#include "Entreprise.h"
#include "Agent.h"
#include "Deal.h"


class Borrower : public Entreprise{
public:
    Borrower(std::string name);
    Deal requestDeal(Agent a);
    void repay(Deal d, Agent a, double amount);
};


#endif //PROJET_BORROWER_H
