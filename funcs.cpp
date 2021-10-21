#include <iostream>
#include <cmath>
#include <float.h>
#include "funcs.h"


// add functions here
double find_distance(int v1[], int v2[], int length)
{
  double total = 0;
  for (int i = 0; i < length; i++){
    double difference = v1[i] - v2[i];
    total += (difference * difference);
  }
  return sqrt(total);
}

void calculate_vector(double freq_vector[], std::string encrypted_string)
{
  int num_of_letters = 0;

  for (int i = 0; i < encrypted_string.length(); i++){
    if (islower(encrypted_string[i])){
      num_of_letters++;
      int ascii = (int) encrypted_string[i];
      freq_vector[ascii - 97]++;
    }
  }

  for (int i = 0; i < 26; i++){
    freq_vector[i] = freq_vector[i] / num_of_letters;
  }
  return;
}

void next_rotation(double freq_vector[]){
  double temp = freq_vector[25];
  for (int i = 25; i > 0; i--){
    freq_vector[i] = freq_vector[i-1];
  }
  freq_vector[0] = temp;
}

/*std::string solve(std::string encrypted_string)
{
  double engf[26] = {0.08167, 0.01492, 0.02782, 0.04253, 	0.12702, 0.02228,
                     0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
                     0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
                     0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
                     0.01974, 0.00074};
  double minimum_distance = DBL_MAX;
  double minimum_rotation;

  for (int i = 0; i < 26; i++){

  }

}*/
