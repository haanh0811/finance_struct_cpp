#ifndef PROJET_FACILITY_H
#define PROJET_FACILITY_H


#include "Lender.h"
#include "Part.h"

class Facility {
private:
    int start;
    int end;
    double lentAmount;
    double stillToRepay;
    float rate;
    std::string devises;
    Lender* lenders[6];
    float proportions[6];
    int size;
    Part* parts[5];
    int partsNb;
public:
    Facility(int start, int fin, double montant, float taux, std::string devises, Lender* lenders[6], float proportions[6],int size);
    void InterstCalculation();
    void applyRepay(double amount);
    float getRate();
    int getAnEnd();
    void setAnEnd(int anEnd);
    int getStart();
    void setStart(int start);
    double getLentAmount() ;
    void setLentAmount(double amount);
    double getStillToRepay();
    void setRate(float rate);
    std::string getDevises();
    void setDevises(std::string devises);
    Lender** getLenders();
    float* getProportions();
    int getSize();
    void setSize(int size);
    Part* repay(double ,int idxFacility);
    
};


#endif //PROJET_FACILITY_H
