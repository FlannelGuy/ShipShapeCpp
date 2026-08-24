#ifndef CONTAINER_H
#define CONTAINER_H
class Container{
protected:
    long id;
    int lbs;

public:
    Container(long id, int lbs);
    Container(int lbs);
    Container();

    const virtual int getContainerType();

    long getId();
    int getLbs();

    bool operator<(const Container& obj){
        return this->getLbs() < obj.lbs;
    }
    bool operator>(const Container& obj){
        return this->getLbs() > obj.lbs;
    }
};

#endif //CONTAINER_H