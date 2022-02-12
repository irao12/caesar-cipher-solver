#pragma once

// add prototypes here
std::string encryptCaesar(std::string plaintext, int rshift);

void find_frequencies(double frequencies[], std::string book);

double find_distance(double v1[], double v2[], int length);

void calculate_vector(double freq_vector[], std::string encrypted_string);

void next_rotation(double freq_vector[]);

std::string solve(std::string encrypted_string, double frequencies[]);
