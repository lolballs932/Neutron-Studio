#pragma region Includes
#include <Windows.h>
#pragma endregion

#pragma region Definitions
	#define MAX_NAME_STRING 256
	#define HInstance() GetModuleHandle(NULL)
#pragma endregion

#pragma region Global Variables
	WCHAR			WindowClass[MAX_NAME_STRING];
#pragma endregion

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	/* - Initialize Global Variables - */
	
	wcscpy_s(WindowClass, TEXT("MainClass"));

	/* - Create Window Class - */

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = DefWindowProc;

	RegisterClassEx(&wcex);

	/* - Create and Display our Window - */

	/* - Listen for Message events - */

	return 0;

}