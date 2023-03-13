#include <HashMap.h>

template <typename K, typename V>
HashMap<K, V>::HashMap(size_t table_size) {
  // initialize the hash map with an empty table
}

template <typename K, typename V>
HashMap<K, V>::~HashMap() {
  // delete all nodes in the hash map and the table array
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
  // compute the hash code for the key
  // find the node in the linked list corresponding to the key
  // if the key is already present, update the value
  // otherwise, insert a new node at the beginning of the list
  // and increment the size of the hash map
  // if the load factor exceeds a threshold, resize the table
}

template <typename K, typename V>
bool HashMap<K, V>::remove(const K& key) {
  // compute the
}