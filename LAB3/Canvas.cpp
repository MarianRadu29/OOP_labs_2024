#include "Canvas.h"
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool Canvas::VerifyPoint(int x, int y)
{
    if (x<0 || x>height)
        return false;
    if (y<0 || y>width)
        return false;
    return true;
}
Canvas::Canvas(int width, int height) : canvas(nullptr), width(width+1), height(height+1) 
{
    canvas = new char* [height+1];
    for (int i = 0; i <= height; i++) 
    {
        canvas[i] = new char[width + 1]; //width + null char
        memset(canvas[i], ' ', width+1);//punem pe primele width pozitii  din linia i caracterul spatiu
        canvas[i][width+1] = '\0';//setam null ul
    }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{   
    
    int a = abs(ray), b = 0, c = 0;
    while (a >= b) 
    {
        SetPoint(x + b, y + a, ch);
        SetPoint(x + a, y + b, ch);
        SetPoint(x + a, y - b, ch);
        SetPoint(x + b, y - a, ch);
        SetPoint(x - b, y - a, ch);
        SetPoint(x - a, y - b, ch);
        SetPoint(x - a, y + b, ch);
        SetPoint(x - b, y + a, ch);

        if (c <= 0) {b += 1; c += 2 * b + 1;}
        if (c > 0) { a -= 1; c -= 2 * a + 1;}
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{     
    
    ray = abs(ray);
    DrawCircle(x, y, ray, ch);
    /*for (int i = x - ray + 1; i < x + ray; i++)
    {   
        int j = y - ray;
        while (canvas[i][j] != ch)
            j++;
        j++;
        while (canvas[i][j] != ch)
            canvas[i][j++] = ch;
    }
    */
    for (int i = x - ray + 1; i < y + ray; i++) 
    {
        bool insideCircle = false;
        for (int j = x - ray + 1; j < x + ray; j++) 
        {
            if (canvas[i][j] == ch)
                insideCircle = !insideCircle;
            if (insideCircle)
                SetPoint(i, j, ch);
        }
    }
    for (int i = x - ray + 1; i < y + ray; i++)
    {
        SetPoint(y, i, ch);
        SetPoint(i, x, ch);
    }    
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{   
    
     DrawLine(left, top, left, bottom,ch);
     DrawLine(right, top, right, bottom, ch);
     DrawLine(left, top, right, top, ch);
     DrawLine(left, bottom, right, bottom, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{   
    
    for (int i = top; i <= bottom; i++)
        DrawLine(left,i,right ,i, ch);
}
void Canvas::SetPoint(int x, int y, char ch)
{   
    if (VerifyPoint(x, y) && ch != '\0')
        canvas[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    
    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    int stepX = (x1 < x2) ? 1 : -1;
    int stepY = (y1 < y2) ? 1 : -1;
    int error = deltaX - deltaY;

    int x = x1;
    int y = y1;
    while (x != x2 || y != y2) 
    {   
        //cout << x << ' ' << y << ' ' << ch << endl;
        SetPoint(x, y, ch);
        int error2 = 2 * error;
        if (error2 > -deltaY) 
        {
            error -= deltaY;
            x += stepX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y += stepY;
        }
    }
    SetPoint(x, y, ch);
}
void Canvas::Print()//shows what was printed
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
            cout << canvas[i][j] << ' ';
        cout << endl;
    }
}
void Canvas::Clear()//clears the canvas
{   
    int i, j;
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            canvas[i][j] = ' ';
}