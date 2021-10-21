#pragma once

// add prototypes here
std::string encryptCaesar(std::string plaintext, int rshift);

double find_distance(int v1[], int v2[], int length);

void calculate_vector(double freq_vector[], std::string encrypted_string);

void next_rotation(double freq_vector[]);

std::string solve(std::string encrypted_string);
