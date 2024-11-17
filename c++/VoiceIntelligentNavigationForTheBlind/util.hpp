#pragma once
#include <iostream>
namespace ns_util
{
	class JsonUtil
	{
	public:
		//È¥³ý±êÇ©<>
		static void removeLabel(std::string& str)
		{
			std::string result;
			size_t start = 0;
			size_t end = str.find('<');

			if (end != std::string::npos)result = str.substr(0, end - start);
			else return;

			//ÇåÏ´
			while (end != std::string::npos)
			{
				start = str.find('>', end) + 1;
				end = str.find('<', end + 1);
				if (end == std::string::npos)break;
				result += str.substr(start, end - start);
			}
			end = str.size();
			result += str.substr(start, end - start);
			swap(str, result);
		}


	};
}
