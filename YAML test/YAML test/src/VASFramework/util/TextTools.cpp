#include "TextTools.hpp"

namespace vas
{
	std::string TextTools::wstos(const std::wstring & value, bool unicode)
	{
		UINT codepage = unicode ? CP_UTF8 : CP_ACP;
		if (value.empty()) return unicode ? u8"" : "";
		int newlength = WideCharToMultiByte(codepage, 0, value.c_str(), -1, nullptr, 0, nullptr, nullptr);
		if (newlength == 0) return unicode ? u8"" : "";
		char* buffer = new char[newlength];
		WideCharToMultiByte(codepage, 0, value.c_str(), -1, buffer, newlength, nullptr, nullptr);
		std::string result(std::move(buffer));
		delete[] buffer;
		return result;
	}

	std::wstring TextTools::stows(const std::string & value, bool unicode)
	{
		UINT codepage = unicode ? CP_UTF8 : CP_ACP;
		if (value.empty()) return L"";
		int newlength = MultiByteToWideChar(codepage, 0, value.c_str(), -1, nullptr, 0);
		if (newlength == 0) return L"";
		wchar_t* buffer = new wchar_t[newlength];
		MultiByteToWideChar(codepage, 0, value.c_str(), -1, buffer, newlength);
		std::wstring result(std::move(buffer));
		delete[] buffer;
		return result;
	}
}