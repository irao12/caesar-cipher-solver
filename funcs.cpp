#include <iostream>
#include <fstream>
#include <cmath>
#include <float.h>
#include "funcs.h"
#include "caesar.h"

// add functions here
void find_frequencies(double frequencies[], std::string book){
  std::ifstream input(book);
  char c;
  int total;
  //reads each char from the file, if a letter is detected its value in the frequency
  //table is incremented. At the end, each value is divided by the total number of
  //letters to determine frequencies in the English alphabet

  while (input >> c){
    if (isalpha(c)){
      total++;
      if (islower(c)){
        int ascii = (int) c;
        frequencies[ascii-97]++;
      }
      else if (isupper(c)){
        int ascii = (int) c;
        frequencies[ascii-65]++;
      }
    }
  }

  for (int i = 0; i < 26; i++){
    frequencies[i] = frequencies[i] / total;
  }
  
  return;
}



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
    else if (isupper(encrypted_string[i])){
      num_of_letters++;
      int ascii = (int) encrypted_string[i];
      freq_vector[ascii-65]++;
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

std::string solve(std::string encrypted_string, double frequencies[])
{
  //setting up the vector for letter frequency in English

  double min_distance = DBL_MAX;
  double min_rotation;

  double freq_vector[26]; // setting up the initial vector from encrypted_string
  for (int i = 0; i < 26; i++) freq_vector[i] = 0;
  calculate_vector(freq_vector, encrypted_string);

  for (int i = 0; i < 26; i++){
    double curr_distance = find_distance(frequencies, freq_vector, 26);
    if (curr_distance < min_distance){
      min_distance = curr_distance;
      min_rotation = i;
    }
    next_rotation(freq_vector);
  }

  return decryptCaesar(encrypted_string, min_rotation);
}
