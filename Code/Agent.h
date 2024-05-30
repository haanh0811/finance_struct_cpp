#ifndef PROJET_AGENT_H
#define PROJET_AGENT_H


#include "Lender.h"
#include "Facility.h"
#include "Deal.h"
#include "Date.h"


class Agent : public Lender{
private:
    Lender* futurePool[5];
    Lender* poolForNextFacility[6];
    float futureProportions[6];
    int sizeFuturePool;
    int sizeNextFacilityPool;

public:
    Agent(std::string name);
    Deal* createDeal(std::string borrowerName, double montant, std::string devise, int start, int fin);
    Facility* UnlockMoney(Deal* d, double amount, std::string devises, int startDate, int endDate, float rate);
    Lender** getFuturePool();
    void setFuturePool(Lender* lenders[5], int size);
    Lender** getPoolForNextFacility();
    void setPoolForNextFacility(Lender* lenders[5], float proportions[5], int size);
};


#endif //PROJET_AGENT_H
