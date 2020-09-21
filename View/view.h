#ifndef VIEW_H_
#define VIEW_H_

#include <windows.h>
#include <windowsx.h>

#include <string>

void WriteText(HDC& hdc, int x, int y, std::string text);

void SelectWaitress(HDC& hdc, HPEN& hPen, HBRUSH& hBrush);
void SelectTeacher(HDC& hdc, HPEN& hPen, HBRUSH& hBrush);
void SelectStudent(HDC& hdc, HPEN& hPen, HBRUSH& hBrush);

void DrawHuman(HDC& hdc, int x, int y);

void DrawTable(HDC& hdc, int x, int y);

#endif  // VIEW_H_
