#include "MyString.h"

TString::TString()
{
	len = 0;
	str = new char[len + 1];
	str[len] = 0;
}

TString::TString(const char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	len = i;
	str = new char[len + 1];
	for (i = 0; i < len + 1; i++)
	{
		str[i] = s[i];
	}
}

TString::TString(int n, char c)
{
	if (n <= 0)
	{
		throw "!";
	}
	len = n;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = c;
	}
	str[len] = 0;
}

TString::TString(const TString& s)
{
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		str[i] = s.str[i];
	}
}

TString::~TString()
{
	if (str != 0)
	{
		delete[] str;
		str = 0;
	}
}

int TString::GetLen()
{
	return len;
}

TString TString::operator+(TString& s)
{
	TString res(len + s.len + 1);
	for (int i = 0; i < len; i++)
	{
		res.str[i] = str[i];
	}
	for (int i = len; i < len + s.len + 1; i++)
	{
		res.str[i] = s.str[i - len];
	}
	return res;
}

TString& TString::operator=(const TString& s)
{
	if (this == &s)
	{
		return *this;
	}
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		str[i] = s.str[i];
	}
	return *this;
}

TString& TString::operator+=(const TString& s)
{
	int l = len + s.len;
	char* res = new char[l + 1];
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	for (int i = len; i < l + 1; i++)
	{
		res[i] = s.str[i - len];
	}
	delete[] str;
	len = l;
	str = res;
	return *this;
}

TString TString::operator+(char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	int l = i;
	TString res(len + l + 1);
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	for (int i = len; i < len + l + 1; i++)
	{
		res[i] = s[i - len];
	}
	return res;
}

TString& TString::operator=(char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	len = i;
	delete[] str;
	str = new char[len + 1];
	for (i = 0; i < len + 1; i++)
	{
		str[i] = s[i];
	}
	return *this;
}

TString& TString::operator+=(char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	int l = len + i;
	char* res = new char[l + 1];
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	for (int i = len; i < l + 1; i++)
	{
		res[i] = s[i - len];
	}
	delete[] str;
	len = l;
	str = res;
	return *this;
}

bool TString::operator==(TString& s)
{
	if (len != s.len)
	{
		return false;
	}
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != s.str[i])
		{
			return false;
		}
	}
	return true;
}

bool TString::operator!=(TString& s)
{
	if (len != s.len)
	{
		return true;
	}
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != s.str[i])
		{
			return true;
		}
	}
	return false;
}

bool TString::operator<(TString& s)
{
	int l = len > s.len ? s.len : len;
	for (int i = 0; i < l; i++)
	{
		if (str[i] < s.str[i])
		{
			return true;
		}
		else if (str[i] > s.str[i])
		{
			return false;
		}
	}
	if (len > s.len)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool TString::operator>(TString& s)
{
	int l = len > s.len ? s.len : len;
	for (int i = 0; i < l; i++)
	{
		if (str[i] < s.str[i])
		{
			return false;
		}
		else if (str[i] > s.str[i])
		{
			return true;
		}
	}
	if (len > s.len)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char& TString::operator[](int i)
{
	if (str == 0)
	{
		throw "!";
	}
	if (i < 0 && i > len)
	{
		throw "!";
	}
	while (i <= 0)
	{
		i = i + len;
	}
	i = i % len;
	return str[i];
}

int TString::find(char c)
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int TString::find(TString& s)
{
	for (int i = 0; i < len - s.len + 1; i++)
	{
		bool f = true;
		for (int j = 0; j < s.len; j++)
		{
			if (str[i + j] != s.str[j])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			return i;
		}
	}
	return -1;
}

TString* TString::split(char c, int &m)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			k = k + 1;
		}
	}
	if (k == 0)
	{
		return 0;
	}
	k = k + 1;
	m = k;

	TString* mas = new TString[k];
	int j = 0;
	int start = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			mas[j].len = i - start;
			delete[] mas[j].str;
			mas[j].str = new char[mas[j].len + 1];
			for (int p = 0; p < mas[j].len; p++)
				mas[j].str[p] = str[p + start];
			mas[j].str[mas[j].len] = 0;
			j = j + 1;
			start = i + 1;
		}
	}
	mas[j].len = len - start;
	delete[] mas[j].str;
	mas[j].str = new char[mas[j].len + 1];
	for (int i = 0; i < mas[j].len + 1; i++)
	{
		mas[j].str[i] = str[i + start];
	}
	return mas;
}

std::ostream& operator<<(std::ostream& a, TString& b)
{
	a << b.str;
	return a;
}

std::istream& operator>>(std::istream& a, TString& b)
{
	char s[100];
	int i = 0;
	a >> s;
	while (s[i] != 0)
	{
		i = i + 1;
	}
	b.len = i;
	delete[] b.str;
	b.str = new char[b.len + 1];
	for (i = 0; i < b.len; i++)
	{
		b.str[i] = s[i];
	}
	b.str[b.len] = 0;
	return a;
}

TString TString::copyNTimes(int n)
{
	TString res;
	for (int i = 0; i < n; i++)
	{
		res += str;
	}
	return res;
}

int* TString::masIndex(TString& s, int& x)
{
	int k = 0;
	for (int i = 0; i < len - s.len + 1; i++)
	{
		bool f = true;
		for (int j = 0; j < s.len; j++)
		{
			if (str[i + j] != s.str[j])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			k = k + 1;
		}
	}
	if (k == 0)
	{
		return 0;
	}
	x = k;

	int* mas = new int[k + 1];
	int t = 0;
	for (int i = 0; i < len; i++)
	{
		bool f = true;
		for (int j = 0; j < s.len; j++)
		{
			if (str[i + j] != s.str[j])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			mas[t] = i;
			t = t + 1;
		}
	}
	return mas;
}

char& TString::frequentElem()
{
	char symbols[256] = {0};
	int count[256] = {0}, max = 0, max_id = 0;
	for (int i = 0; i < 256; i++)
	{
		symbols[i] = (char)i;
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			if (str[i] == symbols[j])
			{
				count[j]++;
			}
			if (count[j] > max)
			{
				max = count[j];
				max_id = j;
			}
		}
	}
	return symbols[max_id];
}

void TString::printCountSymbol()
{
	char symbols[256] = { 0 };
	int count[256] = { 0 };
	for (int i = 0; i < 256; i++)
	{
		symbols[i] = (char)i;
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			if (str[i] == symbols[j])
			{
				count[j]++;
			}
		}
	}
	for (int i = 0; i < 256; i++)
	{
		if (count[i] > 0)
		{
			std::cout << symbols[i] << " - " << count[i] << "\n";
		}
	}
}