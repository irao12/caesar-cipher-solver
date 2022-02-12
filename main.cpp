#include <iostream>
#include "funcs.h"

int main()
{
  //sets up frequency table
  double frequencies[26];
  for (int i = 0; i < 26; i++)
    frequencies[i] = 0;

  find_frequencies(frequencies, "prideandprejudice.txt");

  std::cout << "Test 1:\n" << '\n';
  std::string str = "mary had a little lamb";
  std::cout << "Before encoding: " << '\n' << str << '\n';
  str = encryptCaesar(str, 12);
  std::cout << "\nAfter encoding with rshift 12: " << '\n' << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str, frequencies) << '\n';

  std::cout << "\nTest 2:\n" << '\n';
  str = "betty was a creature of habit and she thought she liked it that way. that was until dave showed up in her life. she now had a choice to make and it would determine whether her lie remained the same or if it would change forever.";
  std::cout << "Before encoding: " << '\n' << str << '\n';
  str = encryptCaesar(str, 19);
  std::cout << "\nAfter encoding with rshift 19: " << '\n' << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str, frequencies) << '\n';

  std::cout << "\nTest 3:" << '\n';
  str = "It was a weird concept. Why would I really need to generate a random paragraph? Could I actually learn something from doing so? All these questions were running through her head as she pressed the generate button. To her surprise, she found what she least expected to see.";
  std::cout << "\nBefore encoding: " << '\n' << str << '\n';
  str = encryptCaesar(str, 6);
  std::cout << "\nAfter encoding with rshift of 6: " << '\n' << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str, frequencies) << "\n";

  std::cout << "\nTest 4:" << '\n';
  str = "no way";
  std::cout << "\nBefore encoding: " << str << '\n';
  str = encryptCaesar(str, 12);
  std::cout << "\nAfter encoding with rshift of 4: " << '\n' << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str, frequencies) << "\n" << " ^ which is wrong since there were too few letters" << "\n\n";
  return 0;
}
