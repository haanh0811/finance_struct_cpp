#ifndef PROJET_DEAL_H
#define PROJET_DEAL_H


#include <string>
#include "Date.h"
#include "Lender.h"
#include "Facility.h"


class Deal {
private:
    std::string contractNumber;
    std::string agent;
    Lender* pool[5];
    std::string borrower;
    double amount;
    double amountToUnlock;
    std::string devise;
    int contractSignature;
    int contractEnd;
    std::string status;
    Facility* facilities[5];
    int facilitiesSize;
public:
    Deal(std::string numContrat, std::string agentName, Lender* b[5], std::string borrowerName, double montant, std::string devise, int signature, int fin);
    std::string toString();
    int getFinContrat();
    int getSignatureContrat();
    double getAmountToUnlock();
    double getAmount();
    std::string getStatus();
    std::string getDevise();
    std::string getAgent();
    std::string getContractNumber();
    std::string getBorrower();
    Lender** getPool();
    Facility** getFacilities();


    void setFinContrat(int fin);
    void setSignatureContrat(int signature);
    void setAmountToUnlock(double montant);
    void setAmountToRepay(double montant);
    void setAmount(double montant);
    void setStatus(std::string& newStatus);
    void setDevise(std::string& newDevise);
    void setAgent(std::string& agentName);
    void setBorrower(std::string& borrowerName);
    void setPool(Lender* b[5]);

    Part* repay(double d, int i);

    Facility *
    createFacility(int i, int i1, double d, float d1, std::string basicString, Lender *pLender[6], float pDouble[6],
                   int i2);

    std::string generateContractNumber();
};


#endif //PROJET_DEAL_H
