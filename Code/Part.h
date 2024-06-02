//
// Created by Julien on 30/05/2024.
//

#ifndef PROJET_PART_H
#define PROJET_PART_H


class Part {
private:
    double repaid;
    int idxFacility;
public:
    Part(double d,int idxFacility);
    double getRepaid();
    int getIdxFacility();
};


#endif //PROJET_PART_H
