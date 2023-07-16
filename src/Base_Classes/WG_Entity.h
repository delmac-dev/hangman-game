#if !defined(WG_ENTITY_H)
#define WG_ENTITY_H

class Entity
{
    private:
        int clientX;
        int clientY;
        int clientHeight;
        int clientWidth;
        int referenceX;
        int referenceY;
        int referenceHeight;
        int referenceWidth;
        bool hasRefPoint;

    protected:
        int getClientX();
        int getClientY();
        int getClientH();
        int getClientW();
        int getRefX();
        int getRefY();
        int getRefH();
        int getRefW();
        void setClientX(int);
        void setClientY(int);
        void setClientH(int);
        void setClientW(int);
        void setRefX(int);
        void setRefY(int);
        void setRefH(int);
        void setRefW(int);
    
    public:
        int setReference(int x, int y, int w, int h);
        int setPosition(int x, int y);
        int setCenter(void);
        int setCenterX(int y);
        int setCenterY(int x);
        int setTopRight(int x, int y);
        int setTopLeft(int x, int y);
        int setBottomRight(int x, int y);
        int setBottomLeft(int x, int y);
};

#endif // WG_ENTITY_H