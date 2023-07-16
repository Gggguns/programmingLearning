#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_7_10_String.h"
const size_t npos = -1;
int main()
{
	zjh::string s = "https://www.baidu.com/?tn=15007414_8_dg";
	string s2 = "https://www.baidu.com/?tn=15007414_8_dg";
	zjh::string s1(s);
	//·¶Î§for
	int i = 0;
	//string s3(s2);
	//s3.reserve(10);
	//s1.reserve(10);
	//cout << s2.capacity() << endl;
	/*zjh::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1;
		it1++;
	}
	cout << endl;*/
	/*s1.append("21e1");
	s1.push_back('s');
	cout << s1.c_str() << endl;*/
	/*printf("%p\n", s2.c_str());*/
	//s2.erase(10);
	//s2.clear();
	//s2 += 'c';
	/*cout << s2.c_str() << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2.push_back('w');
	cout << s2.c_str() << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	printf("%p\n", s2.c_str());*/
	//printf("%p\n", s2.c_str());
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.c_str() << endl;
	s1.resize(10,'o');
	printf("%p\n", s1.c_str());
	zjh::string::iterator it = s1.begin();
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
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