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

int Deal::getFinContrat() { return finContrat; }
int Deal::getSignatureContrat()  { return signatureContrat; }
double Deal::getMontantADebloquer()  { return montantADebloquer; }
double Deal::getMontantProjet() { return montantProjet; }
std::string Deal::getStatus()  { return status; }
std::string Deal::getDevise()  { return devise; }
std::string Deal::getAgent()  { return agent; }
std::string Deal::getNumeroContrat()  { return numeroContrat; }
std::string Deal::getBorrower()  { return borrower; }
Lender** Deal::getPool() { return pool; }


void Deal::setFinContrat(int fin) { finContrat = fin; }
void Deal::setSignatureContrat(int signature) { signatureContrat = signature; }
void Deal::setMontantADebloquer(double montant) { montantADebloquer = montant; }
void Deal::setMontantProjet(double montant) { montantProjet = montant; }
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