#ifndef PROJET_AGENT_H
#define PROJET_AGENT_H


#include "Lender.h"
#include "Facility.h"
#include "Deal.h"
#include "Date.h"


class Agent : public Lender{
public:
    Agent(std::string name);
    Deal* createDeal(Lender* b, std::string borrowerName, std::string numeroContrat, double montant, std::string devise, int fin);
    Facility* UnlockMoney(Deal* d, Lender* b, double amount, std::string* devises, int endDate, float rate);
};


#endif //PROJET_AGENT_H
