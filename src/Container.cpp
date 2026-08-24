#include "Container.hpp"

    Container::Container(long id, int lbs): id(id), lbs(lbs){}
    Container::Container(int lbs):id(0L),lbs(lbs){}
    Container::Container():id(0L),lbs(0){}

    const int Container::getContainerType(){return 0;}

    long Container::getId(){return id;}
    int Container::getLbs(){return lbs;}
