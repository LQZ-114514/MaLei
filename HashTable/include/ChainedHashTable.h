#pragma once
#include<iostream>
#include<vector>

namespace MaLei 
{
class ChainedHashTable 
{
public:
    ChainedHashTable(int capacity);
    ~ChainedHashTable();

    int size() const;
    bool empty() const;

    void put(int key, int value);
    bool contains(int key) const;
    int get(int key) const;
    bool remove(int key);
    void clear();

    int hash(int key) const;
    double loadFactor() const;
    int bucketSize(int index) const;
    int maxBucketSize() const;
    void print() const;

    void rehash(int newCapacity);
    void reserve(int newCapacity);

    std::vector<int> keys() const;
    std::vector<int> values() const;
    int collisionCount() const;
    
private:
    struct Node 
    {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;
    int capacity;
    int count;
};



}