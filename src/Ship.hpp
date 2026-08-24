#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <vector>
#include "TEUCompartment.hpp"
#include "OneTEUContainer.hpp"
#include "TwoTEUContainer.hpp"
class Ship{
protected:
    long id;
    std::string name;

    int width;//X
    int length;//Y
    int height;//Z
    std::vector<std::vector<std::vector<TEUCompartment>>> compartments;
    int numberOfOneTEUContainers;
    int numberOfTwoTEUContainers;
    std::vector<TwoTEUContainer> TwoTEUVector;
    std::vector<OneTEUContainer> OneTEUVector;
public:
    Ship(long id, std::string name, int widthX, int lengthY, int heightZ);
    void loadShip();
    void generateRandomContainerCounts();
    void generateRandomContainerWeights();
    std::vector<TEUCompartment> getSortedCompartmentsVector();
    std::vector<std::vector<std::vector<TEUCompartment>>> getTEUCompartments();
};

#endif //SHIP_H