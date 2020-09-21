#include "view.h"

void WriteText(HDC& hdc, int x, int y, std::string text) {
  TCHAR message[text.size() - 1];
  strcpy(message, text.c_str());
  TextOut(hdc, x, y, message, text.size());
}

void SelectWaitress(HDC& hdc, HPEN& hPen, HBRUSH& hBrush) {
  hPen = CreatePen(PS_SOLID, 2, RGB(255, 192, 203));
  hBrush = CreateSolidBrush(RGB(255, 192, 203));
  SelectPen(hdc, hPen);
  SelectBrush(hdc, hBrush);
}

void SelectTeacher(HDC& hdc, HPEN& hPen, HBRUSH& hBrush) {
  hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 80));
  hBrush = CreateSolidBrush(RGB(255, 0, 80));
  SelectPen(hdc, hPen);
  SelectBrush(hdc, hBrush);
}

void SelectStudent(HDC& hdc, HPEN& hPen, HBRUSH& hBrush) {
  hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
  hBrush = CreateSolidBrush(RGB(0, 0, 255));
  SelectPen(hdc, hPen);
  SelectBrush(hdc, hBrush);
}

void DrawHuman(HDC& hdc, int x, int y) {
  int radius = 15;
  Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

void DrawTable(HDC& hdc, int x, int y) {
  HPEN hPen = CreatePen(PS_SOLID, 2, RGB(139, 69, 19));
  HBRUSH hBrush = CreateSolidBrush(RGB(139, 69, 19));
  SelectPen(hdc, hPen);
  SelectBrush(hdc, hBrush);
  int half_width = 40;
  int half_height = 20;

  Rectangle(hdc,
            x - half_width,
            y - half_height,
            x + half_width,
            y + half_height);

  DeleteObject(hPen);
  DeleteObject(hBrush);
}
