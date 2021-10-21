#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift){
  rshift %= 26;
  if (c >= 65 && c<= 90){
    c += rshift;
    if (c>90) c-=26;
    else if (c<65) c+=26;
  }

  else if (c >= 97 && c <= 122){

    if ((int)c + rshift > 127) c = c - 26 + rshift;
    else if ((int)c + rshift < 128){
      c += rshift;
      if (c > 122) c-= 26;
    }
    if (c < 97) c+=26;

  }

  return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
  for (int i = 0; i < plaintext.length(); i++){
    if (isalpha(plaintext[i])) plaintext[i] = shiftChar(plaintext[i], rshift);
  }
  return plaintext;
}

std::string decryptCaesar(std::string ciphertext, int rshift){
  for (int i = 0; i < ciphertext.length(); i++){
    if (isalpha(ciphertext[i])) ciphertext[i] = shiftChar(ciphertext[i], -1*rshift);
  }
  return ciphertext;
}
