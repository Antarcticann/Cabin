#pragma once
#include <tchar.h>
#include <iostream>
#include <urlmon.h>

#pragma comment(lib, "urlmon.lib")
using namespace std;

int RandomCat()
{
	string url = "https://thiscatdoesnotexist.com";
	size_t len = url.length();
	int nmlen = MultiByteToWideChar(CP_ACP, 0, url.c_str(), len + 1, NULL, 0);
	wchar_t*buffer = new wchar_t[nmlen];
	MultiByteToWideChar(CP_ACP, 0, url.c_str(), len + 1, buffer, nmlen);
	HRESULT hr = URLDownloadToFile(NULL, "https://thiscatdoesnotexist.com", _T("E:\\CQP-xiaoi\\ø·Q Pro\\data\\image\\cat.jpg"), 0, NULL);
	return 0;
}