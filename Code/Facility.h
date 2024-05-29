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
    double amountToRepay;
    double interest;
    float rate;
    std::string devises;
    Lender* lenders[6];
    Deal* deal;
public:
    Facility(Deal* deal, int fin, double montant, float taux, std::string devises, Lender* lenders[6], int size);
    void InterstCalculation();
    void applyRepay(double amount);
    float getRate();
};


#endif //PROJET_FACILITY_H
