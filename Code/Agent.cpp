#include "Agent.h"


Agent::Agent(std::string name) : Lender(name) {

}

Deal* Agent::createDeal(Lender* b, std::string borrowerName, std::string numeroContrat, double montant, std::string devise, int fin) {
    return new Deal(numeroContrat, this->getName(), b, borrowerName,  montant, devise, Date().getTime(), fin);



}

Facility* Agent::UnlockMoney(Deal* d, Lender* b, double amount, std::string* devises, int endDate, float rate) {
    return new Facility(d, endDate, amount, rate, devises, b);
}
