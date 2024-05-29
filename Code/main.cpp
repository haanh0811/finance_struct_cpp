#include <iostream>
#include "Lender.h"
#include "Agent.h"
#include "Borrower.h"

int main() {
    Agent* a = new Agent("BNP");
    Borrower* b = new Borrower("Air France");

    Lender* l1 = new Lender("CA");
    Lender* l2 = new Lender("SG");
    Lender* lenders[2] = {l1,l2};
    a->setFuturePool(lenders);
    Deal* d = b->requestDeal(a, 100, 3);

    std::cout << d->toString() << std::endl;
    for (int i=0; i<5; i++){
        std::cout << d->getPool()[i]->getName() << std::endl;
    }

    return 0;
}
