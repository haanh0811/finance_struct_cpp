#include "Agent.h"


Agent::Agent(std::string name) : Lender(name) {

}

Deal* Agent::createDeal(std::string borrowerName, double montant, std::string devise, int fin) {
    Lender* b;
    std::string numeroContrat;
    return new Deal(numeroContrat, this->getName(), futurePool, borrowerName,  montant, devise, Date().getTime(), fin);
}

Facility* Agent::UnlockMoney(Deal* d, Lender* b, double amount, std::string* devises, int endDate, float rate) {
    return new Facility(d, endDate, amount, rate, devises, b);
}

Lender** Agent::getFuturePool() {
    return futurePool;
}

void Agent::setFuturePool(Lender* lenders[5]) {
    for (int i = 0; i < 5; ++i) {
        futurePool[i] = lenders[i];
    }
}

