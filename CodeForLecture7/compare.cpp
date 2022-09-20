#include <iostream>
#include <string>

int main ()
{
  std::string str1 ("green apple");
  std::string str2 ("red apple");

  // returns an int 
  // if str.compare(str) == 0, strings are equal
  if (str1.compare(str2) != 0)
    std::cout << str1 << " is not " << str2 << '\n';
  else
  std::cout << str1 << " IS a " << str2 << "\n";

  // str1.compare(position, length, comparison string)
  if (str1.compare(6,5,"apple") == 0)
    std::cout << "still, " << str1 << " is an apple\n";

  // str1.compare(4,5, "apple")
  if (str2.compare(str2.size()-5,5,"apple") == 0)
    std::cout << "and " << str2 << " is also an apple\n";

  // str1.compare(starting position, length, comparison string, cs starting index, cs length)
  if (str1.compare(6,5,str2,4,5) == 0)
    std::cout << "therefore, both are apples\n";

  return 0;
}
