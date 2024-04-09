#include <iostream>
#include <string>
#include <cstdint>

#include "LinkedList.cpp"

class HashTable {
private:
  size_t capacity; // available buckets
  size_t size; // used buckets
  size_t mod;
  LinkedList* values;

  std::uint32_t hash_func(const std::string& key) {
    std::uint32_t hash = 2166136261u;
    for (char c : key) {
      hash ^= static_cast<std::uint32_t>(c);
      hash *= 16777619u;
    }
    return hash;
  }

  size_t get_index(const std::string& key, const size_t& cap) {
    return hash_func(key) % cap;
  };

  void resize() {
    size_t new_capacity = capacity * 2;
    LinkedList* new_values = new LinkedList[new_capacity];

    for(size_t i = 0; i < capacity; ++i) {
      Node* current = values[i].head;
      while(current != nullptr) {
        size_t new_idx = get_index(current->key, new_capacity);

        Node* new_node = new Node(current->key, current->val);
        new_node->next = new_values[new_idx].head;
        new_values[new_idx].head = new_node;

        current = current->next;
      };
    };

    delete[] values;
    values = new_values;
    capacity = new_capacity;
  };

public:
  HashTable(size_t start_capacity = 2) : capacity(start_capacity), size(0), mod(2069) {
    values = new LinkedList[capacity];
  };

  void put(const std::string& key, const std::string& val) {
    ++size;
    if(size >= capacity) {
      resize();
    };

    size_t idx = get_index(key, capacity);
    LinkedList& bucket = values[idx];

    if(bucket.head != nullptr) {
      Node* current = bucket.head;
      while( current != nullptr ) {
        if(current->key == key) {
          std::cerr << "Error: duplicate key" << '\n';
          return;
        };
        current = current->next;
      };

      Node* new_node = new Node(key, val);
      new_node->next = bucket.head;
      bucket.head = new_node;
    } else {
      bucket.head = new Node(key, val);
    };
  };

  std::string get(const std::string& key) {
    size_t idx = get_index(key, capacity);
    Node* current = values[idx].head;

    while( current != nullptr ) {
      if(current->key == key) {
        return current->val;
      };
      current = current->next;
    };
    
    std::cerr << "Error: key does not exist" << '\n';
    return "";
  };

  void set(const std::string& key, const std::string& val) {
    size_t idx = get_index(key, capacity);
    Node* current = values[idx].head;

    while( current != nullptr ) {
      if(current->key == key) {
        current-> val = val;
        return;
      };
      current = current->next;
    };

    std::cerr << "Error: '" << key << "' does not exist" << '\n';
  };

  void del(const std::string& key) {
    size_t idx = get_index(key, capacity);
    Node* current = values[idx].head;
    Node* prev = nullptr;

    while(current != nullptr) {
      if(current->key == key) {
        if(prev == nullptr) {
          values[idx].head = current->next;
        } else {
          prev->next = current->next;
        };
        std::cout << "Deleted key: " << key << std::endl;
        delete current;
        return;
      };
      prev = current;
      current = current->next;
    };

    std::cerr << "Error: '" << key << "' does not exist" << '\n';
  };

  bool contains(const std::string& key) {
    const size_t idx = get_index(key, capacity);
    Node* current = values[idx].head;

    while(current != nullptr) {
      if(current->key == key) {
        return true;
      }
      current = current->next;
    }
    return false;
  };

  bool isEmpty() {
    for(size_t i = 0; i < capacity; ++i) {
      if(values[i].head != nullptr) return false;
    }
    return true;
  };

  void display() {
    std::cout << "{";
    for(size_t i = 0; i < capacity; ++i) {
      Node* current = values[i].head;
      while(current != nullptr) {
        std::cout << '\n' << "  \"" << current->key << "\": " << "\"" << current->val << "\"" << ',';
        current = current->next;
      };
    };
    std::cout << '\n' << "}" << '\n';
  };

  void print_buckets() {
    for(size_t i = 0; i < capacity; ++i) {
      std::cout << "Bucket: " << i;
      Node* current = values[i].head;
      while(current != nullptr) {
        std::cout << " (" << current->key << ": " << current->val << ") ";
        current = current->next;
      };
      std::cout << '\n';
    };
  };

  ~HashTable() {
    delete[] values;
  };
};