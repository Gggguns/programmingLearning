#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_7_10_String.h"

int main()
{
	zjh::string s = "https://www.baidu.com/?tn=15007414_8_dg";
	string s2 = "https://www.baidu.com/?tn=15007414_8_dg";
	zjh::string s1(s);
	//·¶Î§for
	int i = 0;
	//string s3(s2);
	//s3.reserve(10);
	s1.reserve(10);
	//cout << s2.capacity() << endl;
	zjh::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1;
		it1++;
	}
	cout << endl;
	//std::string::iterator it3 = s3.begin();
	//std::string::iterator it2 = s2.begin();
	//s1.reserve(10);
	//zjh::string::iterator it1 = s1.begin();
	/*while (it2 != s2.end())
	{
		cout << *it2;
		it2++;
	}*/
	/*while (it3 != s3.end())
	{
		cout << *it3;
		it3++;
	}*/
	/*for (auto ch : s3)
	{
		cout << ch;
	}*/
	/*cout << endl;*/
	/*for (auto ch : s1)
	{
		cout << ch;
	}*/
	/*cout << endl;*/
	/*for (auto ch : s2)
	{
		cout << ch;
	}
	cout << endl;*/
	//Ð­Òé
	string protocol;

	return 0;
}