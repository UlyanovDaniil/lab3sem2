#include <iostream>
#include "MyString.h"
#include <string>

int main()
{
	TString s1;
	TString s2("hello world!");
	TString s3(4, '1');
	TString s4 = s2;

	std::cout << "s1 = " << s1 << "\ts2 = " << s2 << "\ts3 = " << s3 << "\ts4 = " << s4 << "\n";

	std::cout << "length s3 = " << s3.GetLen() << "\n";

	s1 = s2 + s3;

	std::cout << "s1 = s2 + s2 = " << s2 << " + " << s3 << " = " << s1 << "\n";

	s4 += s2;

	std::cout << "s4 += s2 = " << s4 << "\n";

	s3 = s2;

	std::cout << "s3 = s2 = " << s3 << "\n";

	std::cout << "s1 = " << s1 << "\ts2 = " << s2 << "\ts3 = " << s3 << "\ts4 = " << s4 << "\n";

	TString s5("abc");
	TString s6("1234");
	TString s7("hi");
	char cs1[100] = "abcdef";
	char cs2[100] = "qwerty123456";

	std::cout << "s5 = " << s5 << "\ts6 = " << s6 << "\ts7 = " << s7 << "\tcs1 = " << cs1 << "\tcs2 = " << cs2 << "\n";

	s5 = s6 + cs1;

	std::cout << "s5 = s6 + cs1 = " << s6 << " + " << cs1 << " = " << s5 << "\n";

	s7 += cs2;

	std::cout << "s7 += cs2 = " << s7 << "\n";

	s5 = cs1;

	std::cout << "s5 = cs1 = " << s5 << "\n";

	std::cout << "s5 = " << s5 << "\ts6 = " << s6 << "\ts7 = " << s7 << "\n";

	s5 = s6;

	if (s5 == s6)
	{
		std::cout << "s5 == s6" << "\n";
	}
	else
	{
		std::cout << "s5 != s6" << "\n";
	}

	if (s6 != s7)
	{
		std::cout << "s1 != s4" << "\n";
	}
	else
	{
		std::cout << "s1 == s4" << "\n";
	}

	TString s8("abc"), s9("abd");

	if (s6 < s7)
	{
		std::cout << "s6 < s7" << "\n";
	}
	else
	{
		std::cout << "s6 > s7" << "\n";
	}
	
	if (s6 > s7)
	{
		std::cout << "s6 > s7" << "\n";
	}
	else
	{
		std::cout << "s6 < s7" << "\n";
	}

	std::cout << "s3[4] = " << s3[4] << "\ts3[-3] = " << s3[-3] << "\ts3[13] = " << s3[13] << "\n";

	std::cout << "s1:";
	std::cin >> s1;
	std::cout << "s1 = " << s1 << "\n";

	std::cout << "'o' in s4 have position " << s4.find('o') << "\n";

	std::cout << "s3 in s4 have position " << s4.find(s3) << "\n";

	int k = 0;
	TString s10("hello world !");
	TString* mas = s10.split(' ', k);;

	std::cout << "s10 = " << s10 << "\n";

	for (int i = 0; i < k; i++)
	{
		std::cout << "mas[" << i << "] = " << mas[i] << "\n";
	}

	TString s11 = s10.copyNTimes(3);

	std::cout << "s11 = " << s11 << "\n";

	TString s12("world");

	std::cout << "s12 = " << s12 << "\n";

	int* masI = s11.masIndex(s12, k);

	std::cout << "s12 in s11 have indexs:";
	for (int i = 0; i < k; i++)
	{
		std::cout <<  masI[i] << " ";
	}
	std::cout << "\n";

	std::cout << "frequent symbol in s11:" << s11.frequentElem() << "\n";

	s11.printCountSymbol();

    return 0;
}