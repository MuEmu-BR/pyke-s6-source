#pragma once

class CTextBoxController
{
public:
	static short GetSymbolFromVK(WPARAM wParam);
	bool ControlTextBox(KBDLLHOOKSTRUCT Hook);
}; extern CTextBoxController gTextBoxController;