#include"OpenHashTable.h"

namespace MaLei
{
    OpenHashTable::OpenHashTable(int cap) 
    {
        capacity = (cap <= 0) ? 8 : cap;
        count = 0;
        table = new Entry[capacity];
    }

    OpenHashTable::~OpenHashTable() 
    {
        delete[] table;
        table = nullptr;
    }

    int OpenHashTable::size() const
    {   
        return count;
    }

    bool OpenHashTable::empty() const 
    {
        return (count == 0);
    }

    void OpenHashTable::put(int key, int value)
    {
        if(loadFactor() > 0.75)
        {
            rehash(capacity * 2);
        }
        
        int index = hash(key);
        int begin = index;
        while(1)
        {
            if(table[index].state == EMPTY || table[index].state == DELETED)
            {
                table[index].key = key;
                table[index].value = value;
                table[index].state = OCCUPIED;
                count++;
                return;
            }
            else
            {
                if(table[index].key == key)
                {
                    table[index].value = value;
                    return;
                }
            }

            index = (index + 1)% capacity;
            if(index == begin)
                return;
        }
    }

    bool OpenHashTable::contains(int key) const
    {
        return (findIndex(key) != -1);
    }

    int OpenHashTable::get(int key) const
    {
        int index = findIndex(key);
        if (index != -1) 
            return table[index].value;
        return -114514;
    }

    bool OpenHashTable::remove(int key)
    {
        int index = findIndex(key);
        if (index != -1) 
        {
            table[index].state = DELETED;
            count--;
            return true;
        }
        return false;
    }

    void OpenHashTable::clear()
    {
        for(int i = 0; i<capacity;i++)
        {
            table[i].state = EMPTY;
        }
        count = 0;
    }

    int OpenHashTable::hash(int key) const
    {
        return (key % capacity + capacity) % capacity;
    }

    int OpenHashTable::probe(int key, int step) const
    {
        return ((hash(key) + step) % capacity);
    }

    int OpenHashTable::findIndex(int key) const
    {
        for(int step = 0;step < capacity; step++)
        {
            int index = probe(key,step);
            if(table[index].state == EMPTY)
            {
                return -1;
            }
            if(table[index].state == OCCUPIED && table[index].key == key)
            {
                return index;
            }
        }
        return -1;
    }
    double OpenHashTable::loadFactor() const 
    {
        return (double)count / capacity;
    }

    void OpenHashTable::print() const
    {
        for(int i = 0; i < capacity; i++)
        {
            std::cout << "Slot " << i << ": ";
            if(table[i].state == EMPTY)
                std::cout << "EMPTY";
            else if(table[i].state == DELETED)
                std::cout << "DELETED";
            else
                std::cout << "[" << table[i].key << ": " << table[i].value << "]";
            std::cout << std::endl;
        }
    }

    void OpenHashTable::rehash(int newCapacity)
    {
        if(newCapacity <= 0) return;

        Entry* oldTable = table;
        int oldCapacity = capacity;

        capacity = newCapacity;
        count = 0; 
        table = new Entry[capacity];

        for(int i = 0;i < oldCapacity; i++)
        {
            if(oldTable[i].state == OCCUPIED)
            {
                int index = hash(oldTable[i].key);
                int begin = index;

                while(1)
                {
                    if(table[index].state == EMPTY)
                    {
                        table[index].key = oldTable[i].key;
                        table[index].value = oldTable[i].value;
                        table[index].state = OCCUPIED;
                        count++;
                        break;
                    }
                    index = (index + 1) % capacity;
                    if(index == begin)
                        break;
                }
            }
        }
        delete[] oldTable;
    }

}