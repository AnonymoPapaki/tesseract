#include <Windows.h>
#include "Tesseract.Windows.Main.h"



int CALLBACK WinMain(HINSTANCE, HINSTANCE, PSTR, int nShow)
{
	HWND hWnd = Tesseract::Windows::Create();
	MSG msg = { 0 };

	ShowWindow(hWnd, nShow);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}