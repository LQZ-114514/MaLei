#include "MaLei/LinkedList.h"
#include<iostream>
namespace MaLei
{
    LinkedList::LinkedList() 
    {
        Node*head=new Node;
        head->data=9178;
        head->next=nullptr;
        head_=head;
        size_=0;
    }

    LinkedList::~LinkedList()
    {
        Node* cur = head_;
        while(cur != nullptr)
        {
            Node* next = cur->next;
            delete cur;
            cur=next;
        }
        head_ = nullptr;
        size_ = 0;
    }

    void LinkedList::print() const 
    {
        Node* current = head_->next;
        while (current!= nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << "->";
            }
            current = current->next;
        }
        
        std::cout <<std::endl;
    }

    int LinkedList::size() const
    {
        return size_;
    }

    bool LinkedList::empty() const
    {
        if(head_->next == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void LinkedList::pushFront(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head_->next;
        head_->next = newNode;
        size_++;
    }

    void LinkedList::pushBack(int value)
    {
        Node*cur = head_;
        while(cur->next != nullptr)
        {
            cur=cur->next;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        cur->next=newNode;
        size_++;
    }

    void LinkedList::popFront()
    {
        if(!empty())
        {
            Node* temp = head_->next;
            head_->next = temp->next;
            delete temp;
            size_--;
        }
    }

    void LinkedList::popBack()
    {
        if(!empty())
        {
            Node* cur = head_;
            while(cur->next->next != nullptr)
            {
                cur=cur->next;
            }
            Node* temp = cur->next;
            cur->next = nullptr;
            delete temp;
            size_--;
        }
    }

    void LinkedList::insert(int index, int value)
    {
        if(index <= 0) 
        {
            pushFront(value);
        }
        else if(index >= size_) 
        {
            pushBack(value);
        }
        else 
        {
            Node* cur = head_;
            for(int i = 0; i < index; i++) 
            {
                cur = cur->next;
            }
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = cur->next;
            cur->next = newNode;
            size_++;
        }
    }


    void LinkedList::remove(int index)
    {
        if(index <= 0 || index > size_) 
        {
            return;
        }
        Node* cur = head_;
        for(int i = 0; i < index-1; i++) 
        {
            cur = cur->next;
        }
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        size_--;
    }

    int LinkedList::get(int index) const
    {
        if(index <=0 || index >size_)
        {
            std::cout<<" Can't find MaLei!"<<std::endl;
            return 0;
        }
        else
        {
            Node* cur = head_;
            for(int i = 0; i < index; i++) 
            {
                cur = cur->next;
            }
            return cur->data;
        }
    }

    int LinkedList::find(int value) const
    {
        Node* cur = head_->next;
        int index = 1;
        while(cur != nullptr)
        {
            if(cur->data == value)
            {
                return index;
            }
            cur = cur->next;
            index++;
        }
        return -1; // Not found
    }

    void LinkedList::clear()
    {
        if (head_) 
        { 
            Node* cur = head_->next;
            while(cur != nullptr)
            {
                Node* next = cur->next;
                delete cur;
                cur=next;
            }
        }
    size_=0;
    }

    void LinkedList::reverse()
    {
        if(size_<=1)
        return;
        else
        {
        Node* pre = head_->next;
        Node* cur = pre->next;
        pre->next = nullptr;
        while(cur!=nullptr)
        {
            Node* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head_->next = pre;
        }
    }

    int LinkedList::middle()
    {
        Node* cur1 = head_->next;
        Node* cur2 = head_->next;
        if(cur1==nullptr)
        return -1;
        else
        {
            while(cur1->next!=nullptr)
            {
                if(cur1->next->next!=nullptr)
                {
                    cur1=cur1->next->next;
                    cur2=cur2->next;
                }
                else
                    break;
            }
        return cur2->data;
    }
    }

    int LinkedList::kthFromEnd(int k)
    {
        if(k>size_)
        return -1;//Not Found
        else
        {
            Node*cur1 = head_->next;
            Node*cur2 = head_->next;
            for(int i=0;i<k-1;i++)
            {
                cur1 = cur1->next;
            }
            while(cur1->next!=nullptr)
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur2->data;
        }
    }

    bool LinkedList::hasCycle()
    {
        Node *slow = head_;
        Node *fast = head_;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }

    void LinkedList::removeNthFromEnd(int n)
    {
        if (n>size_)
        return;
        else
        {
            Node*cur1 = head_->next;
            Node*cur2 = head_;
            for(int i=0;i<n-1;i++)
            {
                cur1 = cur1->next;
            }
            while(cur1->next!=nullptr)
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            Node* temp = cur2->next;
            cur2->next = temp->next;
            delete temp;
            size_--;
        }
    }

    void LinkedList::removeDuplicates()
    {
        if(!empty())
        {
            Node*cur = head_->next;
            int num = cur->data;
            while(cur->next!=nullptr)
            {
                Node*temp = cur->next;
                if(temp->data == num)
                {
                    cur->next = temp->next;
                    delete temp;
                    size_--;
                }
                else
                {
                    num = temp->data;
                    cur = temp;
                }
            }
        }
    }

    void LinkedList::reverseBetween(int left,int right)
    {
        if(left>=right || right >size_)
        {
            std::cout<<"Can't reverse it!" << std::endl;
            return;
        }
        else
        {
            Node* cur1 = head_;
            
            for(int i=0;i<left-1;i++)
            {
                cur1 = cur1->next;
            }
            
            Node *temp_pre = cur1->next;
            Node *temp_cur = temp_pre->next;
            for(int i=0;i<right - left; i++)
            {
                Node *temp = temp_cur->next;
                temp_cur->next = temp_pre;
                temp_pre = temp_cur;
                temp_cur = temp;
            }
            Node* temp = cur1->next;
            cur1->next = temp_pre;
            Node* cur2 = temp_cur;
            temp->next = cur2;
        }
    }

    void LinkedList::partition(int x)
    {
        Node* newHead = new Node;
        newHead->data = 666;
        newHead->next = nullptr;
        Node*cur = head_;
        Node*newcur = newHead;
        while(cur->next!=nullptr)
        {
            Node*temp = cur->next;
            if(temp->data<x)
            {
                cur = cur->next;
            }
            else
            {
                cur->next = temp->next;
                temp->next = nullptr;
                newcur->next = temp;
                newcur = newcur->next;
            }
        }
        cur->next = newHead->next;
        delete newHead;
    }
      
    bool LinkedList::isPalindrome()
    {
        if(size_ <= 1)
        return true;
        int mid = size_/2;
        reverseBetween(mid+1,size_);
        Node* ptr1 = head_->next;
        Node* ptr2 = head_->next;
        for(int i=0;i<mid;i++)
        {
            ptr2 = ptr2->next;
        }
        bool result = true;
        for(int i = 0;i<mid;i++)
        {
            if(ptr1->data!=ptr2->data)
            {
                result = false;
                break;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        reverseBetween(mid+1,size_);
        return result;
    }
    
    void LinkedList::sort()
    {
        if (size_ <= 1)
        return;
        head_->next = mergeSort(head_->next);
    }

    LinkedList::Node* LinkedList::mergeSort(Node* head)
    {
        if(head == nullptr || head->next == nullptr)
        return head;

        Node* fast = head;
        Node* slow = head;
        while(fast -> next !=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *mid = slow->next;
        slow->next = nullptr;

        Node* left=mergeSort(head);
        Node* right=mergeSort(mid);

        return merge(left,right);
    }

    LinkedList::Node* LinkedList::merge(Node* a,Node* b)
    {
        Node* result = new Node;
        
        result->next = nullptr;
        Node* tail = result;
        while(a!=nullptr&&b!=nullptr)
        {
            if(a->data <= b->data)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = (a != nullptr) ? a : b;
        Node *realResult = result->next;
        delete result;
        return realResult;
    }

}

 