#include <iostream>
#include "funcs.h"

int main()
{
  std::cout << "Test 1:\n" << '\n';
  std::string str = "mary had a little lamb";
  std::cout << "Before encoding: " << str << '\n';
  str = encryptCaesar(str, 12);
  std::cout << "\nAfter encoding with rshift 12: " << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str) << '\n';

  std::cout << "\nTest 2:\n" << '\n';
  str = "betty was a creature of habit and she thought she liked it that way. that was until dave showed up in her life. she now had a choice to make and it would determine whether her lie remained the same or if it would change forever.";
  std::cout << "Before encoding: " << str << '\n';
  str = encryptCaesar(str, 19);
  std::cout << "\nAfter encoding with rshift 19: " << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str) << '\n';

  std::cout << "\nTest 3:" << '\n';
  str = "today i ate at taco bell. i ordered a chicken quesadilla with cheese and tomatoes. i also redeemed my free taco bell reward and ordered nachos and cheese. it was very delicious and i had a great time. i love eating food after computer science lecture. thank you for coming to my ted talk";
  std::cout << "\nBefore encoding: " << str << '\n';
  str = encryptCaesar(str, 6);
  std::cout << "\nAfter encoding with rshift of 6: " << str << '\n';
  std::cout << "\nAfter solving: " << '\n';
  std::cout << solve(str) << '\n';
  return 0;
}
