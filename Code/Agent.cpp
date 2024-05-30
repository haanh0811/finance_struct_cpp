#include "Agent.h"


Agent::Agent(std::string name) : Lender(name) {

}

Deal* Agent::createDeal(std::string borrowerName, double montant, std::string devise, int start, int end) {
    std::string numeroContrat;
    return new Deal(numeroContrat, this->getName(), futurePool, borrowerName,  montant, devise, start, end);
}

Facility* Agent::UnlockMoney(Deal* d, double amount, std::string devises,int startDate, int endDate, float rate) {
    if (amount > d->getAmountToUnlock() || startDate < d->getSignatureContrat() || endDate > d->getFinContrat()){
        throw 1;
    }
    Facility* f =  new Facility(d, startDate, endDate, amount, rate, devises, poolForNextFacility, sizeNextFacilityPool);
    d->setAmountToUnlock(d->getAmountToUnlock() - amount);
    return f;
}

Lender** Agent::getFuturePool() {
    return futurePool;
}

void Agent::setFuturePool(Lender* lenders[5], int size) {
    for (int i = 0; i < size; ++i) {
        futurePool[i] = lenders[i];
    }
    sizeFuturePool = size;
}

Lender** Agent::getPoolForNextFacility() {
    return poolForNextFacility;
}

void Agent::setPoolForNextFacility(Lender **lenders, int size) {
    poolForNextFacility[0] = this;
    for (int i = 0; i < size; ++i) {
        poolForNextFacility[i+1] = lenders[i];
    }
    sizeNextFacilityPool = size+1;
}

