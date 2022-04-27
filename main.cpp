#include "string.h"
#include <string>

int main()
{
  String a;
  String b(9, 'x');
  String c(b);
  a = b;
  std::cout << a.GetStr() << "\n";

  String d;
  d = a + b;

  if (a == b)
  {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }

  std::cout << d.GetLn() << "\n";

  d = "hashdhfpasdk";

  std::cout << "\nFirstTimeWord " << d.FWord("hd") << "\n\n";
  d.KStr(6);

  std::cout << "\nAllWordIndexes "; d.IndsWord("ha");
  std::cout << "\n" << d.FSymb('p');
  std::cout << "\nMostCommonSymb " << d.MostCommonSymb() << "\n";
  std::cout << "\nLetterWithoutRepeat " << d.WithoutRepeat() << "\n";
  std::cout << "\nCountLetters\n"; d.CountLetter();

  if (a > d)
    std::cout << "\ntrue\n";
  else
    std::cout << "\nfalse\n";

  a = "asdjragjka";
  d = "alkdsnfajf";

  if (a > d)
    std::cout << "\ntrue\n";
  else
    std::cout << "\nfalse\n";

  std::cout << a[5] << "\n";

  return 0;
}