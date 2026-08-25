#include "TEUCompartment.hpp"
#include <iostream>
#include <vector>

    const Container* TEUCompartment::getContainers(){
        return containers;
}

    const int TEUCompartment::getTotalCompartmentWeight(){
        int tempWeight{0};
        for(int i =0; i<2 ; i++){
            if(containers[i].getLbs() != 0){
                tempWeight += containers[i].getLbs();
            }
        }
        return tempWeight;
    }

    void TEUCompartment::addContainer(Container& container){
        if(TEUCount ==0){
            containers[0] = container;
            if(container.getContainerType() == 1){
                TEUCount = 1;
            }else if(container.getContainerType() == 2){
                TEUCount = 2;
            }
        }else if( TEUCount ==1 && container.getContainerType() == 2){
            std::cerr << "This Compartment can only fit another 1 TEU Container.\n";
        }else if( TEUCount ==1 && container.getContainerType() == 1){
            containers[1] = container;
            TEUCount = 2;
        }else if(TEUCount == 2){
            std::cerr << "This Compartment is already full.\n";
        }
    }

    const std::vector<Container> TEUCompartment::getCompartmentContainersAsVector(){
        std::vector<Container> compartmentContainers{};
        for(int i =0; i<TEUCount;i++){
            compartmentContainers.push_back(containers[i]);
        }
        return compartmentContainers;
    }

    const std::vector<long> TEUCompartment::getCompartmentContainerIDs(){
        std::vector<long> compartmentContainerIDs{0L};
        for(Container container: getCompartmentContainersAsVector()){
            compartmentContainerIDs.push_back(container.getId());
        }
        return compartmentContainerIDs;
    }

