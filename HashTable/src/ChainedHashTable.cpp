#include"ChainedHashTable.h"

namespace MaLei
{
    ChainedHashTable::ChainedHashTable(int cap)
    {
        if(cap <= 0)
            capacity = 8;
        else
            capacity = cap;
        count = 0;
        table = new Node*[capacity];
        for(int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }
    ChainedHashTable::~ChainedHashTable()
    {
        clear();
        delete[] table;
        table = nullptr;
    }

    int ChainedHashTable::size() const
    {
        return count;
    }
    bool ChainedHashTable::empty() const
    {
        if(count == 0) return 1;
        else return 0;
    }
    void ChainedHashTable::put(int key, int value)
    {
        if (loadFactor() > 0.75) 
        {
            rehash(capacity * 2);
        }

        int index = hash(key);
        Node *cur = table[index];
        while(cur != nullptr)
        {
            if(cur->key == key)
            {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }

        Node *temp = new Node(key,value);
        temp->next = table[index];
        table[index] = temp;
        count++;
    }

    bool ChainedHashTable::contains(int key) const
    {
        int index = hash(key);
        Node *cur = table[index];
        while(cur != nullptr)
        {
            if(cur->key == key)
                return 1;
            cur = cur->next;
        }
        return 0;
    }

    bool ChainedHashTable::remove(int key)
    {
        int index = hash(key);
        Node *cur = table[index];

        if(cur != nullptr && cur->key == key)
        {
            table[index] = cur->next;
            delete cur;
            count--;
            return true;
        }

        while(cur != nullptr)
        {
            if(cur->next != nullptr)
            {
                if(cur->next->key == key)
                {
                    Node* temp = cur->next;
                    cur->next = temp->next;
                    delete temp;
                    count--;
                    return true;
                }
            }
            cur = cur->next;
        }
        return false;
    }

    int ChainedHashTable::get(int key) const
    {
        int index = hash(key);
        Node *cur = table[index];
        while(cur != nullptr)
        {
            if(cur->key == key)
                return cur->value;
            cur = cur->next;
        }
        return -114514;
    }

    void ChainedHashTable::clear()
    {
        for (int i = 0; i < capacity; i++) 
        {
            Node* curr = table[i];
            while (curr != nullptr) 
            {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            table[i] = nullptr;
        }
        count = 0;
    }

    int ChainedHashTable::hash(int key) const 
    {
        return (key % capacity + capacity) % capacity; 
    }
    double ChainedHashTable::loadFactor() const
    {
        return (double)count / capacity;
    }

    int ChainedHashTable::bucketSize(int index) const
    {
        if(index < 0 || index >=capacity)
            return 0;
        int size = 0;
        Node* cur = table[index];
        while(cur != nullptr)
        {
            size++;
            cur = cur->next;
        }
        return size;
    }

    int ChainedHashTable::maxBucketSize() const
    {
        int max = 0;
        for(int i = 0;i<capacity;i++)
        {
            int size = bucketSize(i); 
            if(size > max)
                max = size;
        }
        return max;
    }

    void ChainedHashTable::print() const
    {
        for(int i = 0;i<capacity;i++)
        {
            std::cout << "Bucket" << i << ": ";
            Node* cur = table[i];
            if(cur == nullptr)
            {
                std::cout<<"NULL";
            }
            else
            {
                while(cur != nullptr)
                {
                    std::cout << "[" << cur->key << ":" << cur->value << "]";
                    cur = cur->next;
                    if(cur != nullptr)
                        std::cout << "->";
                }

            }
            std::cout << std::endl;
        }
    }

    void ChainedHashTable::rehash(int newCapacity)
    {
        if(newCapacity <= 0)
        return;

        Node** oldTable = table;
        int oldCapacity = capacity;

        capacity = newCapacity;
        table = new Node*[capacity];
        for(int i = 0;i<capacity;i++)
        {
            table[i] = nullptr;
        }

        for(int i = 0;i<oldCapacity;i++)
        {
            Node* cur = oldTable[i];
            while(cur != nullptr)
            {
                Node* nextNode = cur->next;
                int newIndex = hash(cur->key);
                cur -> next = table[newIndex];
                table[newIndex] = cur;
                cur = nextNode;
            }
        }
        delete[] oldTable;
    }

    void ChainedHashTable::reserve(int newCapacity)
    {
        if (newCapacity > capacity) 
        {
            rehash(newCapacity);
        }
    }

    std::vector<int> ChainedHashTable::keys() const
    {
        std::vector<int> result;
        for(int i = 0;i < capacity; i++)
        {
            Node* cur = table[i];
            while(cur != nullptr)
            {
                result.push_back(cur->key);
                cur = cur->next;
            }
        }
        return result;
    }

    std::vector<int> ChainedHashTable::values() const
    {
        std::vector<int> result;
        for(int i = 0;i < capacity; i++)
        {
            Node* cur = table[i];
            while(cur != nullptr)
            {
                result.push_back(cur->value);
                cur = cur->next;
            }
        }
        return result;
    }

    int ChainedHashTable::collisionCount() const
    {
        int collisionCount = 0;
        for(int i = 0; i < capacity; i++)
        {
            int size = bucketSize(i);
            if(size > 1)
            {
                collisionCount += (size - 1);
            }
        }
        return collisionCount;
    }
}