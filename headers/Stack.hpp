#ifndef STACK_HPP
#define STACK_HPP

#pragma once

#include <string>

class Stack {
private:
  size_t capacity;
  size_t size;
  std::string* values;

  void resize();

public:
  Stack();
  void push(const std::string& val);
  std::string pop();
  std::string peek();
  bool isEmpty();
  void duplicate();
  void left_rotate(size_t n);
  void right_rotate(size_t n);
  void display();
  size_t get_size();
  ~Stack();
};

#endif //STACK_HPP