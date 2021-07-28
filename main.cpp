// Written by Aaron Barge
// Copyright 2020

// This is a simple test program that can help show the precision of BigInt
// This program gives the smallest positive number that is divisible by all
// numbers between 1 and num


#include <iostream>
#include <assert.h>
#include "BigInt.hpp"
 
void min_divis(unsigned long long int num) {
  BigInt result(1);
  unsigned long long int nums[num + 1];
  for (unsigned long long int i = 0; i < num + 1; ++i) {
    nums[i] = i;
  }
  for (unsigned long long int i = 2; i < num + 1; ++i) {
    result *= nums[i];
    for (unsigned long long int j = 2 * i; j < num + 1; j += i) {
      if (nums[j] % nums[i] == 0)
        nums[j] /= nums[i];
    }
  }
  std::cout << "The minimum number divisible by every number between 1 and " << num << ": " << result << std::endl;
}


int main() {
  min_divis(5000);
}