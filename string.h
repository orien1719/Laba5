#pragma once
#include <iostream>

class String
{
protected:
  char* str;
  int ln;
public:
  String();
  String(int ln, char c);
  String(const String& a);
  String(const char* s);
  ~String();

  int GetLn();
  char* GetStr();
  void SetLn(int _ln);
  void SetStr(char* _str);

 String operator + (String& other);
 String operator = (const String& other);
   bool operator == (String & other);
   bool operator < (const String& other);
   bool operator > (const String& other);
   char operator[](int i);
  friend std::ostream& operator << (std::ostream& ostr, const String& other);
  friend std::istream& operator >> (std::istream& istr, String& other);

  int FWord(const char* _str);
  int FSymb(char c);

  void KStr(int k);
  void IndsWord(const char* _str);
  void CountLetter();
  char MostCommonSymb();
  char* WithoutRepeat();

};