#ifndef PROJET_FACILITY_H
#define PROJET_FACILITY_H

#include <string>
#include "Date.h"
#include "Lender.h"
#include <vector>
#include "Deal.h"

class Facility {
private:
    std::string name;
    int priority;
    double size ; //montant total qu'un facility peut prêter
    double remainingAmount;
    double totalInterest;
    double totalRepayment;
    double interestRate;
    std::vector<std::pair<Lender*, double>> lenders ;// Pairs de  lender avec le montant qu'il prête
    //std::string* devises;


public:
    Facility(const std::string& name, double size, double interestRate, int priority);

    void addLender(Lender* lenders[], double* amount, int lenderCount);
    void addInterest(double amount);
    void addRepayment(double amount);
    double getRemainingAmount() const;
    double getTotalInterest() const;
    double getTotalRepayment() const;
    int getPriority() const;
    double calculateInterest(int period) const;
    
};


#endif //PROJET_FACILITY_H
