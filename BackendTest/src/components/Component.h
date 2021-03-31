//
// Created by rhys on 12/02/2021.
//

#ifndef BACKENDTEST_COMPONENT_H
#define BACKENDTEST_COMPONENT_H

#include "PowerData.h"

/** @brief Main component parent class.
 *
 * This is subclassed by any component, and is used for the physics backend.
 *
 * @author Rhys
 * @date 12/02/2021
 */
class Component{
protected:
    int ID; /**<Component ID - set when class is instantiated */

    Component* next; /**<Pointer to next node in LinkedList */

public:

    /** Main function that is used to establish the outputs of the component. This allows the components to be called in a known way.
     *
     * @param input - PowerData struct that has the inputs to this component
     * @return PowerData struct of outputs
     */
    virtual PowerData output(PowerData input) = 0;

    /** Initialiser that sets shared variables between child classes.
     *
     * @param id - Component ID for the child class
     */
    Component(int id): ID(id) {};
};

#endif //BACKENDTEST_COMPONENT_H
