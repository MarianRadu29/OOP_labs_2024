#pragma once
class Canvas
{
	char** canvas;
	int width, height;
	bool VerifyPoint(int x, int y);
public:
	Canvas(int width, int height);//ecran cred
	void DrawCircle(int x, int y, int ray, char ch);//desenare contur cerc
	void FillCircle(int x, int y, int ray, char ch);//umple cerc
	void DrawRect(int left, int top, int right, int bottom, char ch);//contur dreptunghi
	void FillRect(int left, int top, int right, int bottom, char ch);//dreptunghi desenat full
	void SetPoint(int x, int y, char ch);//deseneaza un pixel
	void DrawLine(int x1, int y1, int x2, int y2, char ch);//deseneaza o linie
	void Print();//shows what was printed
	void Clear();//clears the canvas
};

