#include <windows.h>
#include <windowsx.h>

#include <cmath>
#include <commctrl.h>
#include <string>

#include "../Model/student_queue.h"
#include "../Model/teacher_queue.h"
#include "../Model/visitor.h"
#include "../View/view.h"

#define TIMER_1 (WM_USER+1)

LRESULT MessagesHandler(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param);

HINSTANCE instance_handle;

INT WinMain(HINSTANCE instance_handle_arg, HINSTANCE,
            LPSTR /* command_line */, int n_cmd_show) {
  instance_handle = instance_handle_arg;

  // Register the window class.
  const char kClassName[] = "msg_server_class";
  WNDCLASS window_class = {};
  window_class.lpfnWndProc = MessagesHandler;
  window_class.hInstance = instance_handle;
  window_class.lpszClassName = kClassName;
  window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
  window_class.hbrBackground = GetStockBrush(WHITE_BRUSH);
  RegisterClass(&window_class);

  // Create the window.
  HWND handle_of_window = CreateWindowEx(
      /* dwExStyle =    */ 0,
      /* lpClassName =  */ kClassName,
      /* lpWindowName = */ "Kitchen",
      /* dwStyle =      */ WS_OVERLAPPEDWINDOW,
      /* X =            */ CW_USEDEFAULT,
      /* Y =            */ CW_USEDEFAULT,
      /* nWidth =       */ 550,
      /* nHeight =      */ 600,
      /* hWndParent =   */ nullptr,
      /* hMenu =        */ nullptr,
      /* hInstance =    */ instance_handle,
      /* lpParam =      */ nullptr
  );
  if (handle_of_window == nullptr) {
    return 1;
  }

  // Show the window.
  ShowWindow(handle_of_window, n_cmd_show);

  // Run the message loop.
  MSG message = {};
  while (GetMessage(&message, nullptr, 0, 0)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }

  return (int) message.wParam;
}

void Timer1(
    HWND hWindow, UINT messageCode, UINT_PTR idTimer, DWORD nTicks) {
  SendMessage(hWindow, TIMER_1, 0, 0);
}

// Drawing a grid & handling keyboard events
LRESULT MessagesHandler(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param) {
  static int student_count;
  static int teacher_count;
  static StudentQueue student_queue;
  static TeacherQueue teacher_queue;
  static Visitor visitor;
  // If magic is 0 or 1, then teacher will be served
  // else student will be served
  static int magic;

  static HPEN hPen;
  static HBRUSH hBrush;

  switch (message_code) {
    case WM_CREATE: {
      InitCommonControls();

      // initial addons
      magic = 2;
      student_count = 8;
      teacher_count = 10;

      for (int i = 0; i < student_count; i++) {
        student_queue.AddStudent(std::to_string(i));
      }
      for (int i = 0; i < teacher_count; i++) {
        teacher_queue.AddTeacher(std::to_string(i));
      }

      SetTimer(window_handle, TIMER_1, 1000, Timer1);

      InvalidateRect(window_handle, nullptr, true);
    }
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(window_handle, &ps);

      // Write Texts
      WriteText(hdc, 10, 10, "Kitchen");
      WriteText(hdc, 120, 40, visitor.GetText());

      // Draw Waitress
      SelectWaitress(hdc, hPen, hBrush);
      DrawHuman(hdc, 100, 35);

      // Draw Table
      DrawTable(hdc, 100, 80);

      // Draw teachers
      SelectTeacher(hdc, hPen, hBrush);
      TeacherQueue::Iterator* temp_it1 = teacher_queue.CreateIterator();
      int x = 70;
      int y = 165;
      while (!temp_it1->IsEnd()) {
        DrawHuman(hdc, x, y);
        temp_it1->Next();
        y += 40;
      }

      // Draw students
      SelectStudent(hdc, hPen, hBrush);
      StudentQueue::Iterator* temp_it2 = student_queue.CreateIterator();
      x = 140;
      y = 165;
      while (!temp_it2->IsEnd()) {
        DrawHuman(hdc, x, y);
        temp_it2->Next();
        y += 30;
        x += 30;
      }

      // Draw buddy
      if (visitor.GetColor() != RGB(255, 255, 255)) {
        hPen = CreatePen(PS_SOLID,
                         2,
                         RGB(rand() % 256, rand() % 256, rand() % 256));
      } else {
        hPen = CreatePen(PS_SOLID, 2, visitor.GetColor());
      }
      hBrush = CreateSolidBrush(visitor.GetColor());
      SelectPen(hdc, hPen);
      SelectBrush(hdc, hBrush);
      DrawHuman(hdc, 100, 120);

      EndPaint(window_handle, &ps);
      break;
    }
    case TIMER_1: {
      StudentQueue::Iterator* student_iterator = student_queue.CreateIterator();
      TeacherQueue::Iterator* teacher_iterator = teacher_queue.CreateIterator();
      if (magic < 2 && !teacher_iterator->IsEnd()) {
        teacher_iterator->CurrentItem()->Accept(visitor);
        teacher_queue.DeleteTeacher();
        magic++;
      } else if (!student_iterator->IsEnd()) {
        student_iterator->CurrentItem()->Accept(visitor);
        student_queue.DeleteStudent();
        magic = 0;
      } else if (student_iterator->IsEnd() && teacher_iterator->IsEnd()) {
        visitor.Clear();
      } else {
        magic = 0;
      }

      InvalidateRect(window_handle, nullptr, true);
      break;
    }
    case WM_DESTROY: {
      DeleteObject(hPen);
      DeleteObject(hBrush);

      PostQuitMessage(0);
      break;
    }
    default: {
      return DefWindowProc(window_handle, message_code, w_param, l_param);
    }
  }
  return 0;
}
