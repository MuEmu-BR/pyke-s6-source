#pragma once
// ----------------------------------------------------------------------------------------------

class Controller
{
public:
	bool	Load();
	// ----
	static	LRESULT WINAPI Mouse(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Keyboard(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam);
	// ----
	HINSTANCE	Instance;
	BOOL VKF9_State;
	WPARAM	wMouse;
private:
	HHOOK		MouseHook;
	HHOOK		KeyboardHook;
	// ----
}; extern Controller gController;
// ----------------------------------------------------------------------------------------------