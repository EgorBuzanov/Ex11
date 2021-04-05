// Copyright 2021 Egor Buzanov

#include "train.h"

#include <iostream>

Train::Train() {
  first = nullptr;
  last = nullptr;
}

void Train::addCage(bool _light) {
  Cage *new_cage = new Cage();

  if (_light) {
    new_cage->on();
  }

  if (first != nullptr && last != nullptr) {
    new_cage->prev = last;
    last->next = new_cage;
    last = new_cage;
    new_cage->next = first;
    first->prev = new_cage;
  } else if (first != nullptr && last == nullptr) {
    last = new_cage;
    first->next = new_cage;
    new_cage->prev = first;
    new_cage = first;
    first->prev = new_cage;
  } else {
    first = new_cage;
    first->next = first;
    first->prev = first;
  }
}

void Train::print() const {
  if (first != nullptr) {
    Cage *cage = first;
    while (cage != last) {
      std::cout << cage->get() << std::endl;
    }
    std::cout << cage->get() << std::endl;
  }
}

unsigned int Train::getLenght() const {
  if (first == nullptr) {
    return 0;
  }

  int steps = 0;
  Cage *cage = first;

  cage->on();
  while (true) {
    ++steps;
    cage = cage->next;
    while (cage->get() == false) {
      ++steps;
      cage = cage->next;
    }
    cage->off();
    for (size_t i = 0; i < steps; i++) {
      cage = cage->prev;
    }
    if (cage->get() == false) {
      return steps;
    } else {
      steps = 0;
    }
  }
}
