#include "TwoTEUContainer.hpp"


    TwoTEUContainer::TwoTEUContainer(long id, int lbs):Container(id,lbs){}
    TwoTEUContainer::TwoTEUContainer(int lbs):Container(0L,lbs){}

    const int TwoTEUContainer::getContainerType(){return 2;}
