//
// Created by Julien on 30/05/2024.
//

#include "Part.h"

Part::Part(double d,int i) {
    repaid = d;
    idxFacility = i;
}

double Part::getRepaid() {
    return repaid;
}

int Part::getIdxFacility(){
    return idxFacility;
}
