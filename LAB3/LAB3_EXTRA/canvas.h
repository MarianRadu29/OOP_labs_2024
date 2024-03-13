#pragma once
#include<varargs.h>
#include<iostream>
using namespace std;
class Canvas {
    bool VerifyPoint(int x, int y);
    char** canvas;
    int lines , columns;
public:
    // contructor will call the clear method
    Canvas(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};
Canvas::Canvas(int lines, int columns)
{   
    this->lines = lines;
    this->columns = columns;
    canvas = new char* [lines+1];
    for (int i = 0; i <= lines; i++)
    {
        canvas[i] = new char[columns + 2]; //width + null char
        memset(canvas[i], ' ', columns + 1);//punem pe primele width pozitii  din linia i caracterul spatiu
        canvas[i][columns + 1] = '\0';//setam null ul
    }
}
void Canvas::set_pixel(int x, int y, char value)
{
    if (!VerifyPoint(x, y) || value == '\0')
        return;
    canvas[x][y] = value;
}
bool Canvas::VerifyPoint(int x, int y)
{
    if (x<0 || x>this->lines)
        return false;
    if (y<0 || y>this->columns)
        return false;
    return true;
}
void Canvas::set_pixels(int count, ...)
{
    va_list a;//pt numarul variabil de parametrii ai functiei
    va_start(a, count);//preluam primul parametru al functiei
    count = va_arg(a, int);//normal ar trebui sa mi ia al 2 lea argument al functiei,il ia pe primul
    for (int i = 0; i < count; i++)
    {
        int b = va_arg(a, int), c = va_arg(a, int), d = va_arg(a, int);
        //cout << b << ' ' << c<<' ' << d << endl;
        set_pixel(b, c, d);
    }
    va_end(a);//inchidem iteratia ->un fel de f.close()
}
void Canvas::print() const
{
    int i, j;
    for (i = 0; i < lines; i++)
    {
        for (j = 0; j < columns; j++)
            cout << canvas[i][j] << ' ';
        cout << endl;
    }
}
void Canvas::clear()//clears the canvas
{
    int i, j;
    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
            canvas[i][j] = ' ';
}
