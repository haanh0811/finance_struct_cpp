#ifndef PROJET_FACILITY_H
#define PROJET_FACILITY_H


#include "Date.h"
#include "Lender.h"
#include "Deal.h"

class Facility {
private:
    int start;
    int end;
    double amount;
    double amountToDistribute;
    double interest;
    float rate;
    std::string* devises;
    Lender* lenders;
    Deal* deal;
public:
    Facility(Deal* deal, int fin, double montant, float taux, std::string* devises, Lender* lenders);
    void InterstCalculation();
    void applyRepay(double amount);
};


#endif //PROJET_FACILITY_H
