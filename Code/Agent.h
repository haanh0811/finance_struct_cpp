#ifndef PROJET_AGENT_H
#define PROJET_AGENT_H


#include "Lender.h"
#include "Facility.h"
#include "Deal.h"
#include "Date.h"


class Agent : public Lender{
private:
    Lender* futurePool[5];

public:
    Agent(std::string name);
    Deal* createDeal(std::string borrowerName, double montant, std::string devise, int fin);
    Facility* UnlockMoney(Deal* d, Lender* b, double amount, std::string* devises, int endDate, float rate);
    Lender** getFuturePool();
    void setFuturePool(Lender* lenders[5]);
};


#endif //PROJET_AGENT_H
