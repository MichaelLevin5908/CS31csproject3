#include "grid.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib>
using namespace std;

static const int NO_VALUE = numeric_limits<int>::min();

static bool grid[MAXROWS][MAXCOLS];  // true means wall, false means empty
static int nRows = NO_VALUE;         // NO_VALUE means grid not yet initialized
static int nCols;

static void doDraw(int rStart, int cStart, int rEnd, int cEnd, int rRobot, int cRobot);
static void checkPos(int r, int c, string func);

void setSize(int nr, int nc)
{
    if (nr < 1  ||  nr > MAXROWS)
    {
        cout << "setSize: invalid number of rows: " << nr << endl;
        exit(1);
    }
    if (nc < 1  ||  nc > MAXCOLS)
    {
        cout << "setSize: invalid number of columns: " << nc << endl;
        exit(1);
    }
    nRows = nr;
    nCols = nc;
    for (int r = 0; r < nRows; r++)
        for (int c = 0; c < nCols; c++)
            grid[r][c] = false;
}

int getRows()
{
    if (nRows == 0)
    {
        cout << "getRows: You must first call setSize." << endl;
        exit(1);
    }
    return nRows;
}

int getCols()
{
    if (nRows == 0)
    {
        cout << "getCols: You must first call setSize." << endl;
        exit(1);
    }
    return nCols;
}

void setWall(int r, int c)
{
    checkPos(r, c, "setWall");
    grid[r-1][c-1] = true;
}

bool isWall(int r, int c)
{
    checkPos(r, c, "isWall");
    return grid[r-1][c-1];
}

void draw(int rStart, int cStart, int rEnd, int cEnd)
{
    checkPos(rStart, cStart, "draw");
    checkPos(rEnd, cEnd, "draw");
    doDraw(rStart, cStart, rEnd, cEnd, NO_VALUE, NO_VALUE); // don't draw robot
}

void draw(int rStart, int cStart, int rEnd, int cEnd, int rRobot, int cRobot)
{
    checkPos(rStart, cStart, "draw");
    checkPos(rEnd, cEnd, "draw");
    doDraw(rStart, cStart, rEnd, cEnd, rRobot, cRobot);
}

static void doDraw(int rStart, int cStart, int rEnd, int cEnd, int rRobot, int cRobot)
{
    if (rRobot != NO_VALUE)
        checkPos(rRobot, cRobot, "draw");

      // Write header lines of column numbers

    if (nCols >= 10)
    {
        cout << "   ";
        for (int c = 1; c <= nCols; c++)
        {
            int t = c / 10;
            if (t == 0)
                cout << ' ';
            else
                cout << t;
        }
        cout << endl;
    }
    cout << "   ";
    for (int c = 1; c <= nCols; c++)
        cout << (c % 10);
    cout << endl;

      // Draw grid

    for (int r = 1; r <= nRows; r++)
    {
        cout << setw(2) << r << ' ';
        for (int c = 1; c <= nCols; c++)
        {
            char ch = '.';
            if (r == rStart  &&  c == cStart)
                ch = 'S';
            else if (r == rEnd  &&  c == cEnd)
                ch = 'E';
            else if (r == rRobot  &&  c == cRobot)
                ch = 'R';

            if (isWall(r, c))
            {
                if (ch == '.')
                    ch = '*';
                else
                    ch = tolower(ch);
            }
            cout << ch;
        }
        cout << endl;
    }
}

static void checkPos(int r, int c, string func)
{
    if (nRows == 0)
    {
        cout << func << ": You must first call setSize." << endl;
        exit(1);
    }
    if (r < 1  ||  r > nRows  ||  c < 1  ||  c > nCols)
    {
        cout << func << ": invalid position (" << r << "," << c << ")"
                 << endl;
        exit(1);
    }
}