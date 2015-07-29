#include "Tesseract.Windows.Main.h"

HWND gWnd = NULL;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//public
HWND Tesseract::Windows::Create()
{
	WNDCLASSEX wc = { 0 };
	
	wc.cbSize = sizeof(wc);
	wc.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszClassName = L"tesseractmain";
	wc.lpfnWndProc = WndProc;

	RegisterClassEx(&wc);

	return
		CreateWindow(wc.lpszClassName, L"Tesseract", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0,
		CW_USEDEFAULT, 0,
		NULL, NULL, NULL, NULL);
}

//private
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		gWnd = hWnd;
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}