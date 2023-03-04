#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <string>
#include <vector>
#include <filesystem>
#include <windows.h>

auto outPutConsoleMessage(std::string msg)
{

	std::cout << msg << "\n";
}



char* wchar_to_char(const wchar_t* pwchar)
{
	// get the number of characters in the string.
	int currentCharIndex = 0;
	char currentChar = pwchar[currentCharIndex];

	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}

	const int charCount = currentCharIndex + 1;

	// allocate a new block of memory size char (1 byte) instead of wide char (2 bytes)
	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		// convert to char (1 byte)
		char character = pwchar[i];

		*filePathC = character;

		filePathC += sizeof(char);

	}
	filePathC += '\0';

	filePathC -= (sizeof(char) * charCount);

	return filePathC;
}




















HANDLE g_hEvent = 0;
int timers = 1;
BOOL WINAPI HandlerRoutine(
	DWORD dwCtrlType   //  control signal type
)
{
	if (!g_hEvent)
		return FALSE;

	switch (dwCtrlType)
	{
	case CTRL_C_EVENT:


		SetEvent(g_hEvent);
		break;
	case CTRL_BREAK_EVENT:
		outPutConsoleMessage("Ctrl+Break pressed");
		SetEvent(g_hEvent);
		break;
	case CTRL_CLOSE_EVENT:
		outPutConsoleMessage("Close pressed");
		SetEvent(g_hEvent);
		break;
	case CTRL_LOGOFF_EVENT:
		outPutConsoleMessage("User logoff");
		SetEvent(g_hEvent);
		break;
	case CTRL_SHUTDOWN_EVENT:
		outPutConsoleMessage("System shutdown");
		SetEvent(g_hEvent);
		break;
	}

	return TRUE; // as we handle the event
}


void noExit()
{

	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);

	if (g_hEvent)
	{
		outPutConsoleMessage("Ожидание закрытия окна...\n");
		WaitForSingleObject(g_hEvent, INFINITE);
		CloseHandle(g_hEvent);
	}
	else
	{
		outPutConsoleMessage("Ошибка создания эвента\n");
	}
	outPutConsoleMessage("\nНажмите на любую кнопку,для выхода");
	SetConsoleCtrlHandler(HandlerRoutine, FALSE);
	exit(0);
}