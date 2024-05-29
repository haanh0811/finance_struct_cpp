#include "Deal.h"

Deal::Deal(std::string numContrat, std::string agentName, Lender *b, std::string borrowerName, double montant,
           std::string devise, int signature, int fin) {
    numeroContrat = numContrat;
    agent = agentName;
    borrower = borrowerName;
    pool = b;
    montantProjet = montant;
    montantADebloquer = montantProjet;
    devise = devise;
    signatureContrat = signature;
    finContrat = fin;
    status = "Closed";
}
