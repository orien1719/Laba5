#include "string.h"
#include <string.h>
#include <iostream>

int strln(const char* str) {

  int ln = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    ln++;
  }

  return ln;
}

String::String()
{
  ln = 0;
  str = new char[1];
  str[0] = '\0';
}

String::String(int _ln, char c)
{
  ln = _ln;
  str = new char[ln + 1];

  for (int i = 0; i < _ln; i++)
    str[i] = c;

  str[ln] = '\0';
}

String::String(const String& a)
{
  ln = a.ln;
  str = new char[ln + 1];

  for (int i = 0; i < ln; i++)
    str[i] = a.str[i];
  str[ln] = '\0';
}

String::String(const char* s)
{
  if (s == nullptr)
  {
    ln = 0;
    str = new char[1];
    str[0] = '\0';
  }
  else
  {
    ln = strln(s);
    str = new char[ln + 1];

    for (int i = 0; i < ln; i++)
      str[i] = s[i];
    str[ln] = '\0';
  }
}

String::~String()
{
  delete[] str;
}

int String::GetLn()
{
  return ln;
}

char* String::GetStr()
{
  char* a = new char[ln];
  for (int i = 0; i <= ln; i++)
    a[i] = str[i];
  return a;
}

void String::SetLn(int _ln)
{
  ln = _ln;
}

void String::SetStr(char* _str)
{
  
  if (_str == nullptr) throw "Error in SetStr func. Your str = nullptr";

  if (str != nullptr) delete[] str;
  str = new char[strln(_str) + 1];
  str[strln(_str)] = '\0';

  for (int i = 0; i < strln(_str); i++)
  {
    str[i] = _str[i];
  }

  ln = (int)strln(_str);
}

String String::operator+(String& other)
{
  int tlen = ln + other.ln;
  String total(tlen, 0);

  for (int i = 0; i < ln; i++)
    total.str[i] = str[i];

  for (int i = ln; i < tlen; i++)
    total.str[i] = other.str[i - ln];

  str[tlen] = '\0';
  return total;
}

String String::operator=(const String& other)
{
  if (str != nullptr)
  {
    delete[] str;
    str = nullptr;
  }

  ln = other.ln;
  str = new char[ln + 1];

  for (int i = 0; i < ln; i++)
    str[i] = other.str[i];

  str[ln] = '\0';

  return *this;
}

bool String::operator == (String& other)
{
  if (ln == other.ln)
  {
    for (int i = 0; i < ln; i++)
      if (str[i] == other.str[i])
      {
      }
      else
        return false;

    return true;
  }
  return false;
}

bool String::operator<(const String& other)
{
  if (ln < other.ln)
  {
    return true;
  }
  else
    if (ln > other.ln)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < ln; i++)
      {
        if (str[i] < other.str[i])
        {
          return true;
        }
        else
          if (str[i] > other.str[i])
            return false;
      }
    }
  return false;
}

bool String::operator>(const String& other)
{
  if (ln > other.ln)
  {
    return true;
  }
  else
    if (ln < other.ln)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < ln; i++)
      {
        if (str[i] > other.str[i])
        {
          return true;
        }
        else
          if (str[i] < other.str[i])
            return false;
      }
    }
  return false;
}

char String::operator[](int i)
{
  if ((i >= 0) && (i <= ln))
  {
    return str[i];
  }
  else
  {
    throw ("Error");
  }
}

int String::FWord(const char* _str)
{
  int lp = strln(_str);
  bool f;

  for (int i = 0; i <= ln - lp; i++)
  {
    f = true;

    if (str[i] == _str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (str[i + j] == _str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }

      if (f == true)
      {
        return i + 1;
      }
    }
  }

  return -1;
}

int String::FSymb(char c)
{
  for (int i = 0; i < ln; i++)
    if (str[i] == c)
      return i;

  return -1;
}

void String::KStr(int k)
{
  for (int i = 0; i < k; i++)
  {
    std::cout << str << "\n";
  }
}

void String::IndsWord(const char* _str)
{
  int lp = strln(_str);
  bool f;
  bool f1 = false;
  for (int i = 0; i <= ln - lp; i++)
  {
    f = true;

    if (str[i] == _str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (str[i + j] == _str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }

      if (f == true)
      {
        std::cout << i + 1 << " ";
        f1 = true;
      }
    }
  }
  if (f1 == false)
    std::cout << "No result";
}

void String::CountLetter()
{
  char* a = new char[ln];
  int count[512];
  bool c;
  int indx = 0;

  a[ln] = '\0';

  for (int i = 0; i < ln; i++)
  {
    a[i] = '0';
    count[i] = 0;
  }

  for (int i = 0; i < ln; i++)
  {
    c = false;

    for (int j = 0; j < ln; j++)
    {
      if (str[i] == a[j])
      {
        c = true;
        count[j] += 1;
      }
    }

    if (c == false)
    {
      a[indx] = str[i];
      count[indx] = 1;
      indx += 1;
    }

  }

  a[indx] = '\0';

  for (int i = 0; i < indx; i++)
  {
    std::cout << a[i] << " - " << count[i] << "\t";
  }

}

char String::MostCommonSymb()
{
  int a[512];
  char c = '0';
  for (int i = 0; i < 512; i++)
    a[i] = 0;
  for (int i = 0; i < ln; i++)
    a[char(str[i])]++;
  for (int i = 0; i < 512; i++)
    if (a[i] > a[int(char(c))])
      c = char(i);
  return char(c);
}

char* String::WithoutRepeat()
{
  char* a = new char[ln];
  int count[512];
  bool c;
  int indx = 0;

  a[ln] = '\0';

  for (int i = 0; i < ln; i++)
  {
    a[i] = '0';
    count[i] = 0;
  }

  for (int i = 0; i < ln; i++)
  {
    c = false;

    for (int j = 0; j < ln; j++)
    {
      if (str[i] == a[j])
      {
        c = true;
        count[j] += 1;
      }
    }

    if (c == false)
    {
      a[indx] = str[i];
      count[i] = 1;
      indx += 1;
    }

  }

  a[indx] = '\0';
  return a;
}

std::ostream& operator<<(std::ostream& ostr, const String& other)
{
  other.str[other.ln] = '\0';
  ostr << other.str;
  return ostr;
}

std::istream& operator>>(std::istream& istr, String& other)
{
  other.str = nullptr;

  char* tot = new char[1024];
  istr >> tot;

  String a(strln(tot), ' ');

  for (int i = 0; i < strln(tot); i++)
    a.str[i] = tot[i];

  other = a;

  return istr;
}


