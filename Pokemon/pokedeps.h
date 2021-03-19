#pragma once

WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}

int namesize(char *name)
{
	int size = 0;
	int value = name[size];
	do {
		value = name[size];
		size++;
	} while (value != 0);
	return size - 1;
}