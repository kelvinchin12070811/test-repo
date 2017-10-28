#pragma once
#include <Windows.h>
#include <string>
#include <codecvt>
#include <fcntl.h>
#include <io.h>

#define VAS_TEXTTOOLS_GETVARNAME(x) std::wstring(L#x)
#define VAS_TEXTTOOLS_GETVARNAMEU8(x) std::string(u8#x)

#define VAS_TEXTTOOLS_SETLOCAL(object) object.imbue(std::locale(object.getloc(), new std::codecvt_utf8<wchar_t>))
#define VAS_TEXTTOOLS_SETLOCALU8U16(object) object.imbue(std::locale(object.getloc(), new std::codecvt_utf8_utf16<wchar_t>))

namespace vas
{
	class TextTools
	{
	public:
		static std::string wstos(const std::wstring& value, bool unicode = true);	//This function only work on Windows
		static std::wstring stows(const std::string& value, bool unicode = true);	//This function only work on Windows

		static inline void init_stdout() { _setmode(_fileno(stdout), _O_U16TEXT); }
		static inline void init_stdin() { _setmode(_fileno(stdin), _O_U16TEXT); }
	};
}