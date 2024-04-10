#include "../headers/LinkedList.hpp"

Node::Node(const std::string& k, const std::string& v) : key(k), val(v), next(nullptr) {};
LinkedList::LinkedList() : head(nullptr) {};

Node* LinkedList::add_node(Node* node) {
  if(head == nullptr) {
    head = node;
  } else {
    Node* last = head;
    while(last->next != nullptr) {
      last = last->next;
    }
    last->next = node;
  };

  return head;
};

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  };
};