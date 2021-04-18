//
// Created by rhys on 18/04/2021.
//

#ifndef SPICE2_MNASOLUTION_H
#define SPICE2_MNASOLUTION_H

#include <map>
#include <vector>
#include <string>

#include "MNAElement.h"

class MNASolution {
private:

    bool numApproxEquals(double a, double b);
    double getVoltage(MNAElement element);

    bool hasAllCurrents(MNASolution mnaSolution);

    bool hasMatchingElement(MNAElement* element);

public:
    std::map<int, double> nodeVoltages;
    std::vector<MNAElement*> elements;

    MNASolution(std::map<int, double> nodeVoltages, std::vector<MNAElement*> elements);

    bool approxEquals(MNASolution mnaSolution);

    double getNodeVoltage(int nodeIndex);

    double getCurrentForResistor(MNAElement resistor);
};


#endif //SPICE2_MNASOLUTION_H
