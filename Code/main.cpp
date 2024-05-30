#include <iostream>
#include "Lender.h"
#include "Agent.h"
#include "Borrower.h"

/* int main() {
    Agent* a = new Agent("BNP");
    Borrower* b = new Borrower("Air France");

    Lender* l1 = new Lender("CA");
    Lender* l2 = new Lender("SG");
    Lender* l3 = new Lender("Crédit Mutuel");
    int sizeD1 = 3;
    Lender* lendersD1[3] = {l1,l2, l3};
    a->setFuturePool(lendersD1, sizeD1);
    Deal* d1 = b->requestDeal(a, 100, 3);

    Lender* lendersD1F1[1] = {l1};
    a->setPoolForNextFacility(lendersD1F1, 1);

    Facility* f1d1;
    try {
        Facility* f1d1 = a->UnlockMoney(d1, 120, "USD - EUR", 2, 0.1);
    }
    catch(int){
        std::cout << "Montant débloquer supérieur au montant restant à débloquer pour le deal" << std::endl;
    }

    f1d1 = a->UnlockMoney(d1, 20, "USD - EUR", 2, 0.1);

    std::cout << d1->toString() << std::endl;
    for (int i=0; i<3; i++){
        std::cout << d1->getPool()[i]->getName() << std::endl;
    }
    std::cout << f1d1->getRate() << std::endl;

    return 0;
}*/
#include <iostream>
#include "Deal.h"
#include "Lender.h"
#include "Portfolio.h"
#include "Facility.h"

int main() {
    // Création des prêteurs
    Lender lender1("Lender 1");
    Lender lender2("Lender 2");
    Lender lender3("Lender 3");
    Lender lender4("Lender 4");
    Lender lender5("Lender 5");

    Lender* pool[5] = { &lender1, &lender2, &lender3, &lender4, &lender5 };

    // Création des facilités de prêt
    Facility facility1("Facility 1", 1000000, 5, 1); // 1,000,000 à 5% avec priorité 1
    Facility facility2("Facility 2", 500000, 4, 2);  // 500,000 à 4% avec priorité 2
    Facility facility3("Facility 3", 200000, 3, 3);  // 200,000 à 3% avec priorité 3

    // Ajout des prêteurs aux facilités
    double amounts1[] = { 400000, 600000 }; // Amounts lent by Lender 1 and Lender 2
    double amounts2[] = { 200000, 300000 }; // Amounts lent by Lender 3 and Lender 4
    double amounts3[] = { 200000 }; // Amount lent by Lender 5

    Lender* lenders1[] = { &lender1, &lender2 };
    Lender* lenders2[] = { &lender3, &lender4 };
    Lender* lenders3[] = { &lender5 };

    facility1.addLender(lenders1, amounts1, 2);
    facility2.addLender(lenders2, amounts2, 2);
    facility3.addLender(lenders3, amounts3, 1);

    Facility* facilities[3] = { &facility1, &facility2, &facility3 };

    // Création du portefeuille global
    /*Portfolio globalPortfolio;

    // Création du deal
    Deal deal("D001", "Agent X", pool, "Borrower Y", 1700000, "USD", 20230101, 20251231, facilities, &globalPortfolio);

    // Affichage des informations du deal
    std::cout << deal.toString() << std::endl;

    // Calculer les intérêts et distribuer les paiements pour une période
    double totalRepayment = 200000; // Montant à rembourser pour cette période
    int period = 1; // Période de 1 an

    deal.distribute_payments(totalRepayment, period);

    // Afficher les résultats après distribution
    std::cout << "Total Interest: " << deal.calculTotalInterests() << std::endl;
    std::cout << "Total Repayments: " << deal.calculTotalRepayments() << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Facility " << (i + 1) << " Remaining Amount: " << facilities[i]->getRemainingAmount() << std::endl;
        std::cout << "Facility " << (i + 1) << " Total Interest: " << facilities[i]->getTotalInterest() << std::endl;
        std::cout << "Facility " << (i + 1) << " Total Repayment: " << facilities[i]->getTotalRepayment() << std::endl;
    }

    // Afficher le portefeuille des prêteurs
    for (int i = 0; i < 5; ++i) {
        Lender* lender = pool[i];
        std::cout << "Lender " << (i + 1) << " (" << lender->getName() << ") Total Lent: " << lender->getTotalLent() << std::endl;
        std::cout << "Lender " << (i + 1) << " (" << lender->getName() << ") Total Interest Earned: " << lender->getPortfolio()->getInterest() << std::endl;
        std::cout << "Lender " << (i + 1) << " (" << lender->getName() << ") Total Repayment Received: " << lender->getPortfolio()->getRepayment() << std::endl;
    }

    return 0;*/
}