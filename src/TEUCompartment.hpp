#ifndef TEU_COMPARTMENT_H
#define TEU_COMPARTMENT_H
#include "Container.hpp"
#include <vector>
class TEUCompartment{
protected:
long id;
Container containers[2];
int TEUCount;

public:
    const Container* getContainers();
    const int getTotalCompartmentWeight();
    void addContainer(Container& container);
    const std::vector<Container> getCompartmentContainersAsVector();
    const std::vector<long> getCompartmentContainerIDs();
};
#endif //TEU_COMPARTMENT_H