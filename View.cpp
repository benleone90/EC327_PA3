#include <iostream>
#include "View.h"
using namespace std;

View::View()
{
    size = 11;
    scale = 2.0;
    origin = Point2D();
}

void View::Clear()
{
    for (int i = 0; i < view_maxsize; ++i)
    {
        for (int j = 0; j < view_maxsize; ++j)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::Plot(GameObject* ptr)
{
    if (ptr->ShouldBeVisible())
    {
        int x, y;
        if (GetSubscripts(x, y, ptr->GetLocation()) == true)
        {
            if (grid[y][x][0] == '.')
            {
                ptr->DrawSelf(grid[y][x]);
            }
            else
            {
                grid[y][x][0] = '*';
                grid[y][x][1] = ' ';
            }
        }
    }
}

void View::Draw()
{
    int max = view_maxsize;
    for (int i = size-1; i >= 0; i--)
    {
        if (i % int(scale) == 0)
        {
            cout << left << setw(2) << max;
            max -= scale * 2;
        }
        else
        {
            cout << "  ";
        }
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << right << grid[i][j][k];
            }
        }
        cout << '\n';
    }
    cout << "  ";
    int temp = 0;
    for (int i = 0; temp <= view_maxsize; i++)
    {
        if (i % int(scale) == 0)
        {
            cout << setw(2) << temp;
            temp += scale * 2;
        }
        else
        {
            cout << "  ";
        }
    }
    cout << '\n';
}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
    int x = (location.x - origin.x) / scale;
    int y = (location.y - origin.y) / scale;

    if ((x <= view_maxsize) && (y <= view_maxsize))
    {
        out_x = x;
        out_y = y;
        return true;
    }
    else
    {
        cout << "An object is outside the display." << endl;
        return false;
    }    
}