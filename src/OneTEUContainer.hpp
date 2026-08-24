#ifndef ONE_TEU_CONTAINER_H
#define ONE_TEU_CONTAINER_H

#include "Container.hpp"

class OneTEUContainer: public Container{
public:
    OneTEUContainer(long id, int lbs);
    OneTEUContainer(int lbs);
    
    const virtual int getContainerType();
};

#endif //ONE_TEU_CONTAINER_H