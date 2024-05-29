#include "Deal.h"

Deal::Deal(std::string numContrat, std::string agentName, Lender* b[5], std::string borrowerName, double montant,
           std::string devise, int signature, int fin) {
    numeroContrat = numContrat;
    agent = agentName;
    borrower = borrowerName;
    for (int i = 0; i < 5; ++i) {
        pool[i] = b[i];
    }
    montantProjet = montant;
    montantADebloquer = montantProjet;
    devise = devise;
    signatureContrat = signature;
    finContrat = fin;
    status = "Closed";
}
