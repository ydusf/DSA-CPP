#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#pragma once

#include <string>
#include <cstdint>

#include "LinkedList.hpp"

class HashTable {
private:
  size_t capacity; // available buckets
  size_t size; // used buckets
  size_t mod;
  LinkedList* values;

  std::uint32_t hash_func(const std::string& key);
  size_t get_index(const std::string& key, const size_t& cap);
  void resize();

public:
  HashTable();
  void put(const std::string& key, const std::string& val);
  std::string get(const std::string& key);
  void set(const std::string& key, const std::string& val);
  void del(const std::string& key);
  bool contains(const std::string& key);
  bool isEmpty();
  void display();
  void print_buckets();
  ~HashTable();
};

#endif //HASH_TABLE_HPP