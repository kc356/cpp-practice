#pragma once

template <typename K, typename V>
class HashMap
{
public:
    HashMap(size_t table_size = 100);
    void insert(const K& key, const V& value);
    bool remove(const K& key);
    bool contains(const K& key) const;
    const V& get(const K& key) const;
    void clear();
    ~HashMap();

private:
    struct Node {
        K key;
        V value;
        Node* next;
    };
    Node** table_;
    size_t table_size_;
    size_t size_;

    // helper functions
    Node* find_node(const K& key) const;
    void resize_table(size_t new_size);

};