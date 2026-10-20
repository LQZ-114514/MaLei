#pragma once
#include<string>
#include<cstddef>
#include<iostream>

namespace MaLei{

class LinkedList
{
public:
LinkedList();
~LinkedList();


void print() const;
int size() const;

bool empty() const;
void pushFront(int value);
void pushBack(int value);
void popFront();
void popBack();

void insert(int index, int value);
void remove(int index);
int get(int index) const;
int find(int value) const;

void clear();

void reverse();
int middle();
int kthFromEnd(int);
void removeNthFromEnd(int n);
bool hasCycle();

void removeDuplicates();
void reverseBetween(int left,int right);
void partition(int x);

bool isPalindrome();
void sort();
private:
    struct Node
    {
        int data;
        Node*next;
    };

    Node*head_;
    int size_;

    Node* mergeSort(Node* head);
    Node* merge(Node*a,Node*b);
};

}