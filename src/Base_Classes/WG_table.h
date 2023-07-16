#if !defined(WG_TABLE_H)
#define WG_TABLE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "WG_Entity.h"
#include "WG_text.h"

using std::vector;
using std::string;

class Table: public Entity
{
    private:
        int bodyCap;
        int headFontSize;
        int bodyFontSize;
        int totalColumns;
        int totalRows;
        int activeBody;
        int totalPages;
        int cellHeight;
        string fontPath;
        SDL_Color headColor;
        SDL_Color bodyColor;
        int rowSpace;
        int colSpace;
        bool hasHead;
        bool hasBody;
        vector<int> cellWidths;
        vector<Text*> tableHead;
        vector<vector<Text*>> tableBody;
        SDL_Renderer* renderer;
    
    public:
        Table();
        int Init(SDL_Renderer* r, int ypos,int hsize, int bsize, int bcap,int rspace, int cspace, string path);
        int Render();
        int addTableHead(string name, int span);
        int addTableRow(vector<string> data);
        void setHeadCol(SDL_Color c);
        void setBodyCol(SDL_Color c);
        void setColor(SDL_Color hc, SDL_Color bc);
        int viewNext();
        int viewPrev();
        int setCellHeight(int h);
        ~Table();
};

#endif // WG_TABLE_H
