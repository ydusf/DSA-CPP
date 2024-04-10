#include <iostream>
#include <string>
#include <memory>

#include "../headers/Stack.hpp"

Stack::Stack() : capacity(2), size(0) {
  values = new std::string[capacity];
};

void Stack::push(const std::string& val) {
  if(size >= capacity) resize();
  values[size++] = val;
};

std::string Stack::pop() {
  if(isEmpty()) {
    std::cerr << "Error: stack is empty";
    return "";
  };

  return values[--size];
};

std::string Stack::peek() {
  return values[size-1];
};

void Stack::resize() {
  size_t new_capacity = capacity * 2;
  std::string* new_values = new std::string[new_capacity];

  memcpy(new_values, values, size * sizeof(std::string));

  delete[] values;
  values = new_values;
  capacity = new_capacity;
};

void Stack::duplicate() {
  push(values[size-1]);
};

void Stack::left_rotate(size_t n) {
  for(size_t i = 0; i < n-1; ++i) {
    std::string temp = values[i];
    values[i] = values[i+1];
    values[i+1] = temp;
  };
};

void Stack::right_rotate(size_t n) {
  for(size_t i = n-1; i > 0; --i) {
    std::string temp = values[i];
    values[i] = values[i-1];
    values[i-1] = temp;
  };
};

bool Stack::isEmpty() {
  return size == 0;
};

size_t Stack::get_size() {
  return size;
};

void Stack::display() {
  for(size_t i = 0; i < capacity; ++i) {
    std::cout << "Val (" << i << "): " << values[i] << '\n';
  }
};

Stack::~Stack() {
  delete[] values;
};
