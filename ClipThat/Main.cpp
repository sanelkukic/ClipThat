#include <stdio.h>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	string content_to_copy;
	if (argc == 0 || argc == 1)
	{
		for (string line; getline(cin, line);)
		{
			content_to_copy += line;
		}
	}
	else
	{
		content_to_copy = argv[1];
	}
	const char* characters_to_copy = content_to_copy.c_str();
	const size_t len = strlen(characters_to_copy) + 1;
	HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hGlob), characters_to_copy, len);
	GlobalUnlock(hGlob);
	if (!OpenClipboard(0))
	{
		::cout << "Error opening clipboard to write to, you might want to report this error to the GitHub issue tracker:\n";
		::cout << GetLastError();
		return 1;
	}
	if (!EmptyClipboard())
	{
		::cout << "Error emptying clipboard contents, you might want to report this error to the GitHub issue tracker:\n";
		::cout << GetLastError();
		return 1;
	}
	if (!SetClipboardData(CF_TEXT, hGlob))
	{
		::cout << "Error writing text to clipboard, you might want to report this error to the GitHub issue tracker:\n";
		::cout << GetLastError();
		return 1;
	}
	if (!CloseClipboard())
	{
		::cout << "Error closing the clipboard, you might want to report this error to the GitHub issue tracker:\n";
		::cout << GetLastError();
		return 1;
	}
	else
	{
		::cout << "Copied to clipboard successfully!";
		return 0;
	}
}