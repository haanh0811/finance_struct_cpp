#include "Deal.h"
#include <algorithm>

Deal::Deal(const std::string& numContrat, const std::string& agentName, Lender* b[5], const std::string& borrowerName, double montant, const std::string& devise, int signature, int fin, Facility* f[3], Portfolio* p){
    numeroContrat = numContrat;
    agent = agentName;
    borrower = borrowerName;
    for (int i = 0; i < 5; ++i) {
        pool[i] = b[i];
    }
    montantProjet = montant;
    montantADebloquer = montantProjet;
    this->devise = devise;
    signatureContrat = signature;
    finContrat = fin;
    status = "active";
    for (int i = 0; i < 3; ++i) {
        facilities[i] = f[i];
    }
    ptf = p ;
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
Lender** Deal::getPool() { return pool.data(); }


void Deal::setFinContrat(int fin) { finContrat = fin; }
void Deal::setSignatureContrat(int signature) { signatureContrat = signature; }
void Deal::setMontantADebloquer(double montant) { montantADebloquer = montant; }
void Deal::setMontantProjet(double montant) { montantProjet = montant; }
void Deal::setStatus(std::string& newStatus) { status = newStatus; }
void Deal::setDevise(std::string& newDevise) { devise = newDevise; }
void Deal::setAgent(std::string& agentName) { agent = agentName; }
void Deal::setNumeroContrat(std::string& numContrat) { numeroContrat = numContrat; }
void Deal::setBorrower(std::string& borrowerName) { borrower = borrowerName; }
void Deal::setPool(Lender* b[5], int size=5) {
    pool.clear();
    for (int i = 0; i < size; ++i) {
        pool.push_back(b[i]);
    }
}

void Deal::setFacility(Facility* f[3], int size=3) {
    facilities.clear();
    for (int i = 0; i < size; ++i) {
        facilities.push_back(f[i]);
    }
}

void Deal::distribute_payments(double repaymentAmount, int period) {
    // Sort facilities by their priority
    std::sort(facilities.begin(), facilities.end(), [](Facility* a, Facility* b) {
        return a->getPriority() < b->getPriority();
    });

    // Iterate over the sorted facilities and distribute payments
    for (Facility* facility : facilities) {
        // Calculate and add interest for the current period
        double interest = facility->calculateInterest(period);
        facility->addInterest(interest);
        ptf->addInterest(interest);

        // If there is any repayment amount left, allocate it to the facility
        if (repaymentAmount > 0) {
            double repayment = std::min(facility->getRemainingAmount(), repaymentAmount);
            facility->addRepayment(repayment);
            ptf->addRepayment(repayment);
            repaymentAmount -= repayment;
        }
    }
}

double Deal::calcul_total_i() {
    double totalInterest = 0;
    for (Facility* facility : facilities) {
        totalInterest += facility->getTotalInterest();
    }
    return totalInterest;
}

double Deal::calcul_total_repayments() {
    double totalRepayments = 0;
    for (Facility* facility : facilities) {
        totalRepayments += facility->getTotalRepayment();
    }
    return totalRepayments;
}


std::string Deal::toString(){
    return numeroContrat + " "  + agent + " " + borrower;
}

