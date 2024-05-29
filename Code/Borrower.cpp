#include "Borrower.h"


Borrower::Borrower(std::string name) {
    this->setName(name);
}

Deal* Borrower::requestDeal(Agent* a, double d, int fin) {
    std::string devise = "USD";
    return a->createDeal(this->getName(), d, devise, fin);
}
