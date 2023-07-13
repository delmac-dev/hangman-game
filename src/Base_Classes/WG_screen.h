#if !defined(_WG_SCREEN_H_)
#define _WG_SCREEN_H_

class Screen
{
    public:
        virtual void onInit(void);
        virtual void onEvent(void);
        virtual void onRender(void);
        virtual void onLoop(void);
};

#endif // _WG_SCREEN_H_
