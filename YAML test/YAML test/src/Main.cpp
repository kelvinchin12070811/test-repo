#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <yaml.h>
#include <vector>
#include "VASFramework/util/TextTools.hpp"

using namespace std;
using namespace vas;

int wmain(int argc, wchar_t** argv)
{
	vas::TextTools::init_stdin();
	vas::TextTools::init_stdout();
	try
	{
		YAML::Node root = YAML::LoadFile(u8"config.yml"s);
		wcout << TextTools::stows(root[u8"title"s].as<string>()) << endl;
		auto langlist = root[u8"lang list"s];
		for (auto langlistItr = langlist.begin(); langlistItr != langlist.end(); langlistItr++)
		{
			wcout << TextTools::stows(langlistItr->as<string>()) << endl;
		}

		wcout << L"lang en_gb pos: "s << to_wstring(distance(langlist.begin(), find_if(langlist.begin(), langlist.end(), [](const YAML::Node& value) {
			return value.as<string>() == u8"en_gb"s;
		}))) << endl;

		wcout << L"lang count: "s << langlist.size() << endl;
		unsigned int currentLangIndex = root[u8"current lang index"s].as<unsigned int>();
		wcout << to_wstring(currentLangIndex) << endl;
		wcout << endl << TextTools::stows(langlist[currentLangIndex].as<string>()) << endl;

		wcout << endl << TextTools::stows(root[u8"screen ratio"s].as<string>()) << endl;

		wstring buffer = TextTools::stows(YAML::Dump(root));
		wcout << endl << buffer << endl;

		//wofstream output;
		//output.open(L"config 2.yml");
		//if (output.is_open())
		//{
		//	VAS_TEXTTOOLS_SETLOCAL(output);
		//	output << buffer << endl;
		//	output.close();
		//}
	}
	catch (const std::exception& e)
	{
		wcout << TextTools::stows(e.what()) << endl;
	}
	system("pause");
	return 0;
}