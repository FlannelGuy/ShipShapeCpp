#include "OneTEUContainer.hpp"

    OneTEUContainer::OneTEUContainer(long id, int lbs): Container(id,lbs){}
    OneTEUContainer::OneTEUContainer(int lbs): Container(0L,lbs){}
    
    const int OneTEUContainer::getContainerType(){return 1;}

