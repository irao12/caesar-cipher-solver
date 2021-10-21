#include <iostream>
#include <cmath>
#include <float.h>
#include "funcs.h"
#include "caesar.h"

// add functions here
double find_distance(double v1[], double v2[], int length)
{
  double total = 0;
  for (int i = 0; i < length; i++){
    double difference = v1[i] - v2[i];
    total += (difference * difference);
  }
  return total;
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
  double temp = freq_vector[0]; //saves the last element
  for (int i = 0; i < 26; i++){
    freq_vector[i] = freq_vector[i+1]; //shifts the elements one index up
  }
  freq_vector[25] = temp;
}

std::string solve(std::string encrypted_string)
{
  //setting up the vector for letter frequency in English
  double engf[26] = {0.08167, 0.01492, 0.02782, 0.04253, 	0.12702, 0.02228,
                     0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
                     0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
                     0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
                     0.01974, 0.00074};

  double min_distance = DBL_MAX;
  double min_rotation;

  double freq_vector[26]; // setting up the initial vector from encrypted_string
  for (int i = 0; i < 26; i++) freq_vector[i] = 0;
  calculate_vector(freq_vector, encrypted_string);

  for (int i = 0; i < 26; i++){
    double curr_distance = find_distance(engf, freq_vector, 26);
    if (curr_distance < min_distance){
      min_distance = curr_distance;
      min_rotation = i;
    }
    next_rotation(freq_vector);
  }

  return decryptCaesar(encrypted_string, min_rotation);
}
