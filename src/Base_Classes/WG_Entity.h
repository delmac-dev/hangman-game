#if !defined(WG_ENTITY_H)
#define WG_ENTITY_H

struct Entity
{
    int positionX;
    int positionY;
    int clientHeight;
    int clientWidth;

    Entity(int posX, int posY, int width, int height)
    {
        positionX = posX;
        positionY = posY;
        clientWidth = width;
        clientHeight = height;
    };
};

#endif // WG_ENTITY_H