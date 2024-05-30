#ifndef PROJET_DEAL_H
#define PROJET_DEAL_H


#include <string>
#include "Date.h"
#include "Lender.h"
#include "Portfolio.h"
#include "Facility.h"
#include <vector>

class Deal {
private:
    std::string numeroContrat;
    std::string agent;
    Lender* pool[5];
    std::string borrower;
    double montantProjet;
    double montantADebloquer;
    std::string devise;
    int signatureContrat;
    int finContrat;
    std::string status;
    
    //3 tranches sont associés à 1 deal
    Facility* facilities[3];
    //Ptf global pour accumuler les intérêtes et remboursements
    Portfolio *ptf;
public:
    Deal(const std::string& numContrat, const std::string& agentName, Lender* b[5], const std::string& borrowerName, double montant, const std::string& devise, int signature, int fin, Facility* f[3], Portfolio* p);
    ~Deal();
    std::string toString();
    int getFinContrat();
    int getSignatureContrat();
    double getMontantADebloquer();
    double getMontantProjet();
    std::string getStatus();
    std::string getDevise();
    std::string getAgent();
    std::string getNumeroContrat();
    std::string getBorrower();
    Lender** getPool();

    void setFinContrat(int fin);
    void setSignatureContrat(int signature);
    void setMontantADebloquer(double montant);
    void setMontantProjet(double montant);
    void setStatus(std::string& newStatus);
    void setDevise(std::string& newDevise);
    void setAgent(std::string& agentName);
    void setNumeroContrat(std::string& numContrat);
    void setBorrower(std::string& borrowerName);
    void setPool(Lender* b[5], int size);
    void setFacility(Facility* f[3], int size);
    void distribute_payments(double repaymentAmount, int period);
    double calcul_total_i();
    double calcul_total_repayments();
    double calculTotalInterests() const;
    double calculTotalRepayments() const;
};


#endif //PROJET_DEAL_H
