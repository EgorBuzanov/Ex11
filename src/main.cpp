// Copyright 2021 Egor Buzanov
#include <iostream>
#include <random>
#include <string>

#include "train.h"

int main() {
  Train train;
  std::random_device rd;
  std::mt19937 mersenne(rd());

  for (size_t i = 0; i < 10; i++) {
    train.addCage(mersenne() % 2);
  }

  train.print();
  std::cout << train.getLenght() << std::endl;
  train.print();

  return 0;
}
