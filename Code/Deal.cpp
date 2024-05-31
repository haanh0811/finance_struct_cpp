#include <sstream>
#include "Deal.h"
#include "Facility.h"

Deal::Deal(std::string numContrat, std::string agentName, Lender* b[5], std::string borrowerName, double montant,
           std::string devise, int signature, int fin) {
    contractNumber = generateContractNumber();
    agent = agentName;
    borrower = borrowerName;
    for (int i = 0; i < 5; ++i) {
        pool[i] = b[i];
    }
    amount = montant;
    amountToUnlock = amount;
    devise = devise;
    contractSignature = signature;
    contractEnd = fin;
    status = "Active";
    facilitiesSize = 0;
}

int Deal::getFinContrat() { return contractEnd; }
int Deal::getSignatureContrat()  { return contractSignature; }
double Deal::getAmountToUnlock()  { return amountToUnlock; }
double Deal::getAmount() { return amount; }
std::string Deal::getStatus()  { return status; }
std::string Deal::getDevise()  { return devise; }
std::string Deal::getAgent()  { return agent; }
std::string Deal::getContractNumber()  { return contractNumber; }
std::string Deal::getBorrower()  { return borrower; }
Lender** Deal::getPool() { return pool; }
int Deal::getNumberOfFacilities(){ return facilitiesSize; }

void Deal::setFinContrat(int fin) { contractEnd = fin; }
void Deal::setSignatureContrat(int signature) { contractSignature = signature; }
void Deal::setAmountToUnlock(double montant) { amountToUnlock = montant; }
void Deal::setAmount(double montant) { amount = montant; }
void Deal::setStatus(std::string& newStatus) { status = newStatus; }
void Deal::setDevise(std::string& newDevise) { devise = newDevise; }
void Deal::setAgent(std::string& agentName) { agent = agentName; }
void Deal::setBorrower(std::string& borrowerName) { borrower = borrowerName; }
void Deal::setPool(Lender* b[5]) {
    for (int i = 0; i < 5; ++i) {
        pool[i] = b[i];
    }
}

std::string Deal::toString(){
    return contractNumber + " " + agent + " " + borrower;
}

Part* Deal::repay(double d, int i) {
    Part* p = facilities[i]->repay(d,i);
    if (facilities[i]->getStillToRepay() == 0){
        bool isTrue = true;
        for (int j=0; j<facilitiesSize; j++){
            if (facilities[j] != 0){
                isTrue = false;
            }
        }
        if (isTrue){
            status = "Terminated";
        }
    }
    return p;
}

Facility * Deal::createFacility(int startDate, int endDate, double sum, float rate, std::string devises, Lender **poolForNextFacility, float *futureProportions,
                     int sizeNextFacilityPool) {
    amountToUnlock -= sum;
    if(amountToUnlock == 0){
        status = "Closed";
    }
    facilities[facilitiesSize] = new Facility(startDate, endDate, sum, rate, devises, poolForNextFacility, futureProportions, sizeNextFacilityPool);
    facilitiesSize++;
    return facilities[facilitiesSize];
}

Facility **Deal::getFacilities() {
    return facilities;
}

std::string Deal::generateContractNumber() {
    char toReturn[4];
    char letter[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i=0; i<3; i++){
        toReturn[i] = letter[rand() % 26];
    }
    toReturn[3] = (char) ((rand()%10)+'0');
    return toReturn;
}
