#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#pragma once

#include <string>

struct Node {
  std::string key;
  std::string val;
  Node* next;

  Node(const std::string& k, const std::string& v);
};

struct LinkedList {
  Node* head;
  
  LinkedList();
  Node* add_node(Node* node);
  ~LinkedList();
};

#endif //LINKED_LIST_HPP