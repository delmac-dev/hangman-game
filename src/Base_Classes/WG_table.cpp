#include <iostream>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>

#include "WG_table.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

Table::Table()
{
    bodyCap = 10;
    headFontSize = 18;
    bodyFontSize = 16;
    totalColumns = 0;
    activeBody = 0;
    totalPages = 1;
    totalRows = 0;
    cellHeight = 30;
    headColor = {255, 255, 255, 255};
    bodyColor = {255, 255, 255, 255};
    rowSpace = 10;
    colSpace = 10;
    hasHead = false;
    hasBody = false;
    renderer = NULL;
}

/**
 * Initialise a table
 * 
 * @param r the renderer the table should use
 * @param ypos set the y position of the tabe
 * @param hsize the table head font size to use, 10 by default, set to -1 to use default
 * @param bsize the table body font to use, 16 by default, set to -1 to use default
 * @param bcap the max amount of rows the table body should hold, 10 by default, set to -1 to use default
 * @param rspace the space between each row, 10 by default, set to -1 to use default
 * @param cspace the space between each column , 10 by default, set to -1 to use default
 * @param path set the font type face path to use
 * 
 * @return 0 on sucess
*/
int Table::Init(SDL_Renderer* r, int ypos,int hsize, int bsize, int bcap,int rspace, int cspace, string path)
{
    renderer = r;
    hsize == -1 ? headFontSize = 18 : headFontSize = hsize;
    bsize == -1 ? bodyFontSize = 16 : bodyFontSize = bsize;
    bcap == -1 ? bodyCap = 10 : bodyCap = bcap;
    rspace == -1 ? rowSpace = 10 : rowSpace = rspace;
    cspace == -1 ? colSpace = 10 : colSpace = cspace;
    fontPath = path;
    setClientY(ypos);

    return 0;
}

/**
 * Set the Tabe Head Infomation 
 * make sure to set the color of the font with the setHeadCol or setColor methods
 * else defaults to white
 * 
 * @param name the name of the column your are creating
 * @param span the width the column should have
 * 
 * @returns 0 on success
*/
int Table::addTableHead(string name, int span)
{
    if(!hasHead) hasHead = true;
    totalColumns ++;
    tableHead.push_back(new Text);
    tableHead.back()->Init(renderer, name, fontPath, headFontSize, headColor);

    cellWidths.push_back(span);
    totalPages = ceil(totalColumns / bodyCap) == 0 ? 1 : ceil(totalColumns / bodyCap);

    int tempSum = 0;
    for (auto i : cellWidths)
        tempSum += i + colSpace;
    setClientW(tempSum);

    return 0;
}

/**
 * Set the data for each row
 * make sure the args are of the name number as the table heads
 * make sure to set the set the color of the body using setBodyCol or setColor method
 * or else would use a default white color
 * 
 * @param data the data to be placed in the table
*/
int Table::addTableRow(vector<string> data)
{
    if(!hasBody) hasBody = true;
    totalRows++;
    vector<Text*> temp;
    for(auto i : data)
    {
        temp.push_back(new Text);
        temp.back()->Init( renderer, i, fontPath, bodyFontSize, bodyColor);
    }

    tableBody.push_back(temp);

    int tempSum = 0;
    for (int i=0 ; i < bodyCap+1; i++)
        tempSum += rowSpace + cellHeight; 
    setClientH(tempSum);
    setCenterX(getClientY());
    return 0;
}

void Table::setHeadCol(SDL_Color c)
{
    headColor = c;
}

void Table::setBodyCol(SDL_Color c)
{
    bodyColor = c;
}

void Table::setColor(SDL_Color hc, SDL_Color bc)
{
    setHeadCol(hc);
    setBodyCol(bc);
}


int Table::viewNext()
{
    int temp = activeBody;
    if(temp+1 > (totalPages-1)) return 1;

    activeBody++;

    temp = activeBody;
    if(temp+1 > (totalPages-1)) return 1;
    
    return 0;
}

int Table::viewPrev()
{
    int temp = activeBody;
    if(temp-1 < 0) return 1;

    activeBody--;

    temp = activeBody;
    if(temp-1 < 0) return 1;

    return 0;
}

int Table::setCellHeight(int h)
{
    cellHeight = h;
    return 0;
}

int Table::Render()
{
    int itr = 0;
    int widthAccount = 0;
    for (auto i : tableHead)
    {
        i->setReference(getClientX() + widthAccount + colSpace * itr, getClientY(), cellWidths[itr], cellHeight);
        i->setCenter();
        widthAccount += cellWidths[itr];
        itr++;

        i->Render();
    }

    int itry = 1;
    int heightAccount = cellHeight;
    for (int i = bodyCap*activeBody; i < (bodyCap + (bodyCap*activeBody)); i++)
    {
        if(i >= tableBody.size()) continue;
        int itrx = 0;
        int widthAccount = 0;
        for (auto j : tableBody[i])
        {
            j->setReference(getClientX() + widthAccount + colSpace * itrx, 
                            getClientY() + heightAccount + rowSpace * itry, 
                            cellWidths[itrx], cellHeight);
            j->setCenter();
            widthAccount += cellWidths[itrx];
            itrx++;

            j->Render();
        }

        heightAccount += cellHeight;
        itry ++;
    }
    return 0;
}

Table::~Table()
{};

