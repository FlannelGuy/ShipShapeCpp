#include <vector>
#include <iostream>
#include "OneTEUContainer.hpp"
#include "TwoTEUContainer.hpp"
#include "Ship.hpp"

int main(){

    Ship myShip(1L,"CMA CGM Florida",11,18,14);
    myShip.generateRandomContainerWeights( );
    myShip.loadShip( );
    std::vector< Container > middleCompartmentContainers = myShip.getTEUCompartments( )[5][0][0].getCompartmentContainersAsVector( );
    std::vector< Container > middleCompartmentLastContainers = myShip.getTEUCompartments( )[5][17][0].getCompartmentContainersAsVector( );
    std::vector< Container > middleLeftCompartmentContainers = myShip.getTEUCompartments( )[4][0][0].getCompartmentContainersAsVector( );
    std::vector< Container > middleRightCompartmentContainers = myShip.getTEUCompartments( )[6][0][0].getCompartmentContainersAsVector( );
    std::cout << "debug breakpoint here.\n";
    std::cout << middleCompartmentContainers.at(0).getLbs() << "\n";
    std::cout << middleCompartmentLastContainers.at(0).getLbs() << "\n";
    std::cout << middleLeftCompartmentContainers.at(0).getLbs() << "\n";
    std::cout << middleRightCompartmentContainers.at(0).getLbs() << "\n";
    return 0;
}