#include <iostream>
#include "WG_Entity.h"

using std::string;

int Entity::getClientX()
{
    if(!hasRefPoint) return 0;
    return clientX;
};
int Entity::getClientY() 
{
    if(!hasRefPoint) return 0;
    return clientY;
};
int Entity::getClientH() 
{
    return clientHeight;
};
int Entity::getClientW()
{
    return clientWidth;
};
int Entity::getRefX() 
{
    if(!hasRefPoint) return 0;
    return referenceX;
};
int Entity::getRefY() 
{
    if(!hasRefPoint) return 0;
    return referenceY;
};
int Entity::getRefH() 
{
    if(!hasRefPoint) return 0;
    return referenceHeight;
};
int Entity::getRefW() 
{
    if(!hasRefPoint) return 0;
    return referenceWidth;
};

void Entity::setClientX( int i) 
{
    clientX = i;
};
void Entity::setClientY( int i) 
{
    clientY = i;
};
void Entity::setClientH( int i) 
{
    clientHeight = i;
};
void Entity::setClientW( int i) 
{
    clientWidth = i;
};
void Entity::setRefX( int i) 
{
    referenceX = i;
};
void Entity::setRefY( int i) 
{
    referenceY = i;
};
void Entity::setRefH( int i) 
{
    referenceHeight = i;
};
void Entity::setRefW( int i) 
{
    referenceWidth = i;
};

/**
 * Set the reference to the object this entity is bound by.
 * Note that the reference position has to be set before 
 * it can be centered with the setCenter method
 * 
 * @param x the x position of the reference 
 * @param y the y position of the reference 
 * @param w the width of the reference entity
 * @param h the height of the reference entity
 * 
 * @return 0 on success
*/
int Entity::setReference(int x, int y, int w, int h)
{
    if ( !hasRefPoint ) hasRefPoint = true;
    setRefX(x);
    setRefY(y);
    setRefH(h);
    setRefW(w);

    return 0;
}

int Entity::setPosition(int x, int y)
{
    setClientX(x);
    setClientY(y);
};

/**
 * NOTE: this should be called only if the setReference method has been called
 * 
 * @return 0 on success
*/
int Entity::setCenter(void)
{
    if (!hasRefPoint) return 1;
    int x = (( getRefW() - getClientW())/ 2) + getRefX();
    int y = (( getRefH() - getClientH())/ 2) + getRefY();

    setPosition(x, y);

    return 0;
};

int Entity::setCenterX(int y)
{
    if (!hasRefPoint) return 1;
    int x = (( getRefW() - getClientW())/ 2) + getRefX();

    setPosition(x, y);

    return 0;
};

int Entity::setCenterY(int x)
{
    if (!hasRefPoint) return 1;
    int y = (( getRefH() - getClientH())/ 2) + getRefY();

    setPosition(x, y);

    return 0;
};
