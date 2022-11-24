#pragma once
//#include <Windows.h>

// commonMacroFunction.h

inline void MakeLine(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

inline RECT SetRect(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;
}

inline RECT SetRectCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2),
		x + (width / 2), y + (height / 2) };

	return rc;
}

// �� �׸��� �Լ� 
// �Ű����� 1	: int x (left)
//				: int y	(top)
//				: int width
//				: int height
inline void MakeEllipse(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}


// �� �׸��� �Լ� 
// �Ű����� 1	: int x (center x)
//				: int y (center y)
//				: int width
//				: int height
inline void MakeEllipseCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}

inline POINT MakePoint(int _x, int _y) {
	POINT pt = { _x, _y };
	return pt;
}