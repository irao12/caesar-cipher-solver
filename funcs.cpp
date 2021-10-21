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
