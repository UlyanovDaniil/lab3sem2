#pragma once
#include <iostream>

class TString
{
public:

    TString();
    TString(const char* s);
    TString(int n, char c = 0);
    TString(const TString& s);
    ~TString();

    int GetLen();

    TString operator+(TString& s);
    TString& operator=(const TString& s);
    TString& operator+=(const TString& s);
    TString operator+(char* s);
    TString& operator=(char* s);
    TString& operator+=(char* s);
    bool operator==(TString& s);
    bool operator!=(TString& s);
    bool operator<(TString& s);
    bool operator>(TString& s);
    char& operator[](int i);

    int find(char c);
    int find(TString& s);
    TString* split(char c, int &m);

    friend std::ostream& operator<<(std::ostream& a, TString& b);
    friend std::istream& operator>>(std::istream& a, TString& b);

    TString copyNTimes(int n);
    int* masIndex(TString& s, int& k);
    char& frequentElem();
    void printCountSymbol();

private:
    char* str;
    int len;
};