#include <algorithm>
#include "Ship.hpp"
#include "Container.hpp"
#include "utils.hpp"

Ship::Ship(long id, std::string name, int widthX, int lengthY, int heightZ):
    id(id),name(name),width(widthX),length(lengthY),height(heightZ),numberOfOneTEUContainers(0),numberOfTwoTEUContainers(0)
{
    compartments.resize(widthX);
    for (int x = 0; x < widthX; ++x) {
        compartments[x].resize(lengthY);
        for (int y = 0; y < lengthY; ++y) {
            compartments[x][y].resize(heightZ); // Sets z and default-initializes complex numbers
        }
    }

}

void Ship::loadShip(){
    std::vector<TEUCompartment> compartmentVector = getSortedCompartmentsVector();
    bool OddWidthCompartmentShip = width % 2 != 0;
    if( OddWidthCompartmentShip ) {
            for( int z = 0; z < height; z++ ) {
                int middleRowLeft = ( width / 2 ) - 1;
                int middleRow = ( width / 2 );
                int middleRowRight = middleRow + 1;
                //iterate through the left and right of center, -1 from the left and +1 on the right
                for( int y = 0; y < length; y++ ) {
                    compartments[middleRow][y][z] = compartmentVector.at(0);
                    compartmentVector.erase(compartmentVector.begin());
                }
                while( middleRowLeft >= 0 && middleRowRight < width ) {
                    //repeat down the length of the ship
                    for( int y = 0; y < length; y++ ) {
                        compartments[middleRowLeft][y][z] = compartmentVector.at(0);
                        compartmentVector.erase(compartmentVector.begin());

                        compartments[middleRowRight][y][z] = compartmentVector.at(0);
                        compartmentVector.erase(compartmentVector.begin());

                    }
                    middleRowLeft--;
                    middleRowRight++;
                }
            }
        } else {
            //for even width ships
            //repeat from lowest to highest level
            for( int z = 0; z < height; z++ ) {
                int middleRowLeft = ( width / 2 ) - 1;
                int middleRowRight = middleRowLeft + 1;
                //iterate through the left and right of center, -1 from the left and +1 on the right
                while( middleRowLeft >= 0 && middleRowRight < width ) {
                    //repeat down the length of the ship
                    for( int y = 0; y < length; y++ ) {
                        compartments[middleRowLeft][y][z] = compartmentVector.at(0);
                        compartmentVector.erase(compartmentVector.begin());
                        compartments[middleRowRight][y][z] = compartmentVector.at(0);
                        compartmentVector.erase(compartmentVector.begin());
                    }
                    middleRowLeft--;
                    middleRowRight++;
                }
            }
        }
}

void Ship::generateRandomContainerCounts(){

    int maxTEU = width * (length *2) * height;
    int split = utils::getRandomNumberBetween(0,((maxTEU/2) +1)) * 2; 
    numberOfOneTEUContainers = maxTEU - split;
    numberOfTwoTEUContainers = split / 2;
}

void Ship::generateRandomContainerWeights(){

    long idCount = 0L;
    if(numberOfOneTEUContainers ==0 && numberOfTwoTEUContainers ==0){
        Ship::generateRandomContainerCounts();
    }

    int OneTEUMin = 40000;
    int OneTEUMax = 53000;

    for( int i =0; i < numberOfOneTEUContainers; i++){
        OneTEUVector.push_back(OneTEUContainer( idCount++,utils::getRandomNumberBetween(OneTEUMin,OneTEUMax+1)));
    }

    int TwoTEUMin = 52900;
    int TwoTEUMax = 67200;

    for( int i =0; i < numberOfTwoTEUContainers; i++){
        TwoTEUVector.push_back(TwoTEUContainer( idCount++,utils::getRandomNumberBetween(TwoTEUMin,TwoTEUMax+1)));
    }

}

std::vector<TEUCompartment> Ship::getSortedCompartmentsVector(){
    std::vector< TEUCompartment > tempOneTEUCompartments{};
    std::vector< TEUCompartment > tempTwoTEUCompartments{};

    std::sort(OneTEUVector.begin(),OneTEUVector.end());
    std::reverse(OneTEUVector.begin(),OneTEUVector.end());
    
    std::sort(TwoTEUVector.begin(),TwoTEUVector.end());
    std::reverse(TwoTEUVector.begin(),TwoTEUVector.end());

    for(int i =0; i< OneTEUVector.size();i+=2){
        TEUCompartment tempCompartment{};
        tempCompartment.addContainer(OneTEUVector.at(i));
        tempCompartment.addContainer(OneTEUVector.at(i+1));
        tempOneTEUCompartments.push_back(tempCompartment);
    }

    for( TwoTEUContainer TwoTEUContainer: TwoTEUVector){
        TEUCompartment tempCompartment{};
        tempCompartment.addContainer(TwoTEUContainer);
        tempTwoTEUCompartments.push_back(tempCompartment);
    }

    std::vector <TEUCompartment > finalCompartmentVector{};
    finalCompartmentVector.insert(finalCompartmentVector.end(),tempOneTEUCompartments.begin(),tempOneTEUCompartments.end());
    finalCompartmentVector.insert(finalCompartmentVector.end(),tempTwoTEUCompartments.begin(),tempTwoTEUCompartments.end());
    return finalCompartmentVector;
}

std::vector<std::vector<std::vector<TEUCompartment>>> Ship::getTEUCompartments(){
    return compartments;
}