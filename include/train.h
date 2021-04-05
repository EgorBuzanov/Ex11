// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Cage {
  bool light;

 public:
  Cage* next;
  Cage* prev;
  Cage() : light(false), next(nullptr), prev(nullptr) {}
  void on() { light = true; }
  void off() { light = false; }
  bool get() const { return light; }
};

class Train {
 private:
  Cage* first;
  Cage* last;

 public:
  Train();
  void addCage(bool);
  void print() const;
  unsigned int getLenght() const;
};

#endif  // INCLUDE_TRAIN_H_
