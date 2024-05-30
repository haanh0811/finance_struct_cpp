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
    int size;
public:
    Facility(Deal* deal, int fin, double montant, float taux, std::string devises, Lender* lenders[6], int size);
    void InterstCalculation();
    void applyRepay(double amount);
    float getRate();
    int getAnEnd();
    void setAnEnd(int anEnd);
    int getStart();
    void setStart(int start);
    double getAmount() ;
    void setAmount(double amount);
    double getAmountToRepay() ;
    void setAmountToRepay(double amountToRepay);
    double getInterest();
    void setInterest(double interest);
    void setRate(float rate);
    std::string getDevises();
    void setDevises(std::string devises);
    Lender** getLenders();
    Deal *getDeal() ;
    void setDeal(Deal *deal);
    int getSize();
    void setSize(int size);
};


#endif //PROJET_FACILITY_H
