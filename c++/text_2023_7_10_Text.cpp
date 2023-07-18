#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_7_10_String.h"
void text_string1()
{
	zjh::string s = "https://www.baidu.com/?tn=15007414_8_dg";
	zjh::string s1(s);
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.c_str() << endl;
	s1.resize(10, 'o');
	printf("%p\n", s1.c_str());
	zjh::string::iterator it = s1.begin();
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}
void text_string2()
{
	zjh::string s1="acsac";
	zjh::string s2 = "caca";
	cout << "交换之前：" << endl;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	s1.swap(s2);
	cout << "交换之后：" << endl;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

}
void text_string3()
{
	zjh::string s = "https://www.baidu.com/?tn=15007414_8_dg";
	string s2 = "https://www.baidu.com/?tn=15007414_8_dg";
	string s3 = "https://cn.bing.com/search?q=protocol&form=IPRV10";
	size_t pos1 = s3.find("://", 0);
	//协议
	zjh::string protocol = s.substr(0, pos1);
	size_t pos2 = s.find('/', pos1 + 3);
	zjh::string domain = s.substr(pos1+3, pos2 - (pos1 + 3));
	zjh::string resource = s.substr(pos2 + 1);
	cout << "协议："<<protocol.c_str() << endl;
	cout << "域名："<<domain.c_str() << endl;
	cout << "资源名："<<resource.c_str() << endl;
	//string s4;
}
void text_string4()
{
	zjh::string s = "cancabncanc";
	size_t pos = s.find('b');
	s.insert(0, "  hello world ");
	cout << s.c_str()<<endl;
}
void text_string5()
{
	zjh::string s = "hello";
	//s += 'h';
	s += " hihi";
	cout << s.c_str() << endl;
}
void text_string6()
{
	//char s[128] = "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddds";
	zjh::string s="cnajsn";
	cin >> s;
	cout << s << endl;
	cin >> s;
	cout << s << endl;
	//zjh::string s1 = s;
	//cout << s1 << endl;
}
void text_string7()
{
	string s1 = "xajlxl\0ackjasn";
	string s2 = "xajlxl\0bckjasn";
	string s3 = "lllllllll";
	string s4 = "ll";
	zjh::string s5 = "xajlxl\0ackjasn";
	zjh::string s6 = "xajlxl\0bckjasn";
	zjh::string s7 = "lllllllll";
	zjh::string s8 = "ll";
	cout << (s1 < s2) << ' ' << (s5 < s6) << endl;
	cout << (s1 == s2) << ' ' << (s5 == s6) << endl;
	cout << (s1 > s2) << ' ' << (s5 > s6) << endl;
	cout << endl;
	cout << (s3 < s4) << ' ' << (s7 < s8) << endl;
	cout << (s3 == s4) << ' ' << (s7 == s8) << endl;
	cout << (s3 > s4) << ' ' << (s7 > s8) << endl;
	cout << endl;


}
int main()
{
	text_string6();

	/*zjh::string s = "https://www.baidu.com/?tn=15007414_8_dg";
	string s2 = "https://www.baidu.com/?tn=15007414_8_dg";
	zjh::string s1(s);	
	zjh::string::iterator it = s.begin();*/
	
	//范围for
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
	

	return 0;
}