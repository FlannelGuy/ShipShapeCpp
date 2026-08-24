#ifndef TWO_TEU_CONTAINER_H
#define TWO_TEU_CONTAINER_H

#include "Container.hpp"

class TwoTEUContainer: public Container{
public:
    TwoTEUContainer(long id, int lbs);
    TwoTEUContainer(int lbs);

    const virtual int getContainerType();
};

#endif //TWO_TEU_CONTAINER_H