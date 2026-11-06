#pragma once
#include <vector>
#include <iostream>

namespace MaLei 
{
enum State 
{
    EMPTY,
    OCCUPIED,
    DELETED
};
class OpenHashTable 
{
public:
    OpenHashTable(int capacity);
    ~OpenHashTable();

    int size() const;
    bool empty() const;
    void put(int key, int value);
    bool contains(int key) const;
    int get(int key) const;
    bool remove(int key);
    void clear();

    int hash(int key) const;
    int probe(int key, int step) const;
    int findIndex(int key) const;
    double loadFactor() const;
    void print() const;

    void rehash(int newCapacity);
    std::vector<int> keys() const;
    int clusterCount() const;
    int longestCluster() const;
    double averageProbeLength() const;
private:
    struct Entry 
    {
        int key;
        int value;
        State state;
        
        Entry() : key(0), value(0), state(EMPTY) {}
    };

    Entry* table;
    int capacity;
    int count;
};
}