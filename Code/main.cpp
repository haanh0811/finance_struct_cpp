#include <iostream>
#include "Lender.h"
#include "Agent.h"
#include "Borrower.h"

int main() {
    Agent* a = new Agent("BNP");
    Borrower* b = new Borrower("Air France");

    Lender* l1 = new Lender("CA");
    Lender* l2 = new Lender("SG");
    Lender* l3 = new Lender("Crédit Mutuel");
    int sizeD1 = 3;
    Lender* lendersD1[3] = {l1,l2, l3};
    a->setFuturePool(lendersD1, sizeD1);
    Deal* d1 = b->requestDeal(a, 100, 3);
    for (int i=0; i<3; i++){
        std::cout << d1->getPool()[i]->getName() << std::endl;
    }

    std::cout << std::endl << "Facility 1" << std::endl;
    Lender* lendersD1F1[1] = {l1};
    a->setPoolForNextFacility(lendersD1F1, 1);
    Facility* f1d1;
    f1d1 = a->UnlockMoney(d1, 20, "USD - EUR", 2, 0.1);
    std::cout << d1->toString() << std::endl;
    std::cout << "D1 - Montant à débloquer:" << d1->getMontantADebloquer() << std::endl;
    for (int i=0; i<3; i++){
        std::cout << d1->getPool()[i]->getName() << std::endl;
    }
    std::cout << f1d1->getRate() << std::endl;
    for(int i = 0; i<f1d1->getSize(); i++){
        std::cout << f1d1->getLenders()[i]->getName() << std::endl;
    }

    std::cout << std::endl << "Facility 2" << std::endl;
    Lender* lendersD1F2[2] = {l2, l3};
    a->setPoolForNextFacility(lendersD1F2, 2);
    Facility* f2d1 = a->UnlockMoney(d1, 60, "SGD", 3, 0.2);
    std::cout <<  f2d1->getAmount() << std::endl;
    std::cout << "D1 - Montant à débloquer:" << d1->getMontantADebloquer() << std::endl;
    std::cout << "Number of lenders:" <<  f2d1->getSize() << std::endl;
    for(int i = 0; i<f2d1->getSize(); i++){
        std::cout << f2d1->getLenders()[i]->getName() << std::endl;
    }
    std::cout << std::endl << "Facility 3" << std::endl;
    Lender* lendersD1F3[1] = {l2};
    a->setPoolForNextFacility(lendersD1F3, 1);
    Facility* f3d1 = a->UnlockMoney(d1, 20, "SGD", 3, 0.2);
    std::cout << "D1 - Montant à débloquer:" << d1->getMontantADebloquer() << std::endl;
    std::cout << f3d1->getRate() << std::endl;
    std::cout << "Number of lenders:" <<  f3d1->getSize() << std::endl;
    for(int i = 0; i<f3d1->getSize(); i++){
        std::cout << f3d1->getLenders()[i]->getName() << std::endl;
    }



    return 0;
}
