#include <iostream>

struct Node {
  std::string key;
  std::string val;
  Node* next;

  Node(const std::string& k, const std::string& v) : key(k), val(v), next(nullptr) {};
};

struct LinkedList {
  Node* head;

  LinkedList() : head(nullptr) {};

  Node* add_node(Node* node) {
    if(head == nullptr) {
      head = node;
    } else {
      Node* last = head;
      while(last->next != nullptr) {
        last = last->next;
      }
      last->next = node;
    }

    return head;
  };

  ~LinkedList() {
    Node* current = head;
    while(current != nullptr) {
      Node* next = current->next;
      delete current;
      current = next;
    };
  };
};