#include "Deal.h"
#include "Facility.h"

Deal::Deal(std::string numContrat, std::string agentName, Lender* b[5], std::string borrowerName, double montant,
           std::string devise, int signature, int fin) {
    numeroContrat = numContrat;
    agent = agentName;
    borrower = borrowerName;
    for (int i = 0; i < 5; ++i) {
        pool[i] = b[i];
    }
    amount = montant;
    amountToUnlock = amount;
    devise = devise;
    signatureContrat = signature;
    finContrat = fin;
    status = "Closed";
    facilitiesSize = 0;
}

int Deal::getFinContrat() { return finContrat; }
int Deal::getSignatureContrat()  { return signatureContrat; }
double Deal::getAmountToUnlock()  { return amountToUnlock; }
double Deal::getAmount() { return amount; }
std::string Deal::getStatus()  { return status; }
std::string Deal::getDevise()  { return devise; }
std::string Deal::getAgent()  { return agent; }
std::string Deal::getNumeroContrat()  { return numeroContrat; }
std::string Deal::getBorrower()  { return borrower; }
Lender** Deal::getPool() { return pool; }


void Deal::setFinContrat(int fin) { finContrat = fin; }
void Deal::setSignatureContrat(int signature) { signatureContrat = signature; }
void Deal::setAmountToUnlock(double montant) { amountToUnlock = montant; }
void Deal::setAmountToRepay(double montant) { amountToRepay = montant; }
void Deal::setAmount(double montant) { amount = montant; }
void Deal::setStatus(std::string& newStatus) { status = newStatus; }
void Deal::setDevise(std::string& newDevise) { devise = newDevise; }
void Deal::setAgent(std::string& agentName) { agent = agentName; }
void Deal::setNumeroContrat(std::string& numContrat) { numeroContrat = numContrat; }
void Deal::setBorrower(std::string& borrowerName) { borrower = borrowerName; }
void Deal::setPool(Lender* b[5]) {
    for (int i = 0; i < 5; ++i) {
        pool[i] = b[i];
    }
}

std::string Deal::toString(){
    return numeroContrat + " "  + agent + " " + borrower;
}

Part* Deal::repay(double d, int i) {
    return facilities[i]->repay(d);
}

Facility * Deal::createFacility(int startDate, int endDate, double sum, float rate, std::string devises, Lender **poolForNextFacility, float *futureProportions,
                     int sizeNextFacilityPool) {
    amountToUnlock -= sum;
    facilities[facilitiesSize] = new Facility(startDate, endDate, sum, rate, devises, poolForNextFacility, futureProportions, sizeNextFacilityPool);
    facilitiesSize++;
    return facilities[facilitiesSize];
}

Facility **Deal::getFacilities() {
    return facilities;
}
