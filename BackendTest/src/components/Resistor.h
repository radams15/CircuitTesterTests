//
// Created by rhys on 12/02/2021.
//

#ifndef BACKENDTEST_RESISTOR_H
#define BACKENDTEST_RESISTOR_H

#include "Component.h"

/** @brief Resistor class that applies a resistance to a voltage.
 *
 * @author Rhys
 * @date 12/02/2021
 */
class Resistor : public Component{
private:

    float resistance; /**<The resistance that this resistor applies */

public:
    /**
     * Initialises the resistor
     * @param resistance - The resistance of the resistor
     */
    Resistor(float resistance);



    PowerData output(PowerData input) override;
};


#endif //BACKENDTEST_RESISTOR_H
