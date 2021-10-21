#include <iostream>
#include <cmath>
#include "funcs.h"


// add functions here
double find_distance(int v1[], int v2[], int length){
  double total = 0;
  for (int i = 0; i < length; i++){
    double difference = v1[i] - v2[i];
    total += (difference * difference);
  }
  return sqrt(total);
}

void calculate_vector(double vector[], std::string encrypted_string){
  int num_of_letters = 0;

  for (int i = 0; i < encrypted_string.length(); i++){
    if (islower(encrypted_string[i])){
      num_of_letters++;
      int ascii = (int) encrypted_string[i];
      vector[ascii - 97]++;
    }
  }

  for (int i = 0; i < 26; i++){
    vector[i] = vector[i] / num_of_letters;
  }
  return;
}

//std::string solve(std::string encrypted_string)
