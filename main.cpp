#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
struct SLNode
{
    T data;
    SLNode<T> *Next;
    SLNode(SLNode<T> *nextNode = nullptr){
        Next = nextNode;
    }

    SLNode(const T &item, SLNode<T>*nextNode = nullptr){
        data = item;
        Next = nextNode
    }
};
template <typename T>
class SList{
private:
    SLNode<T> *head;
    SLNode<T> *tail;
    SLNode<T> *currptr;
public:
    SList();
    SList(const T &item);
    ~SList();
    bool IsEmpty()const;
    int Length()const;
    bool Find(int index, const T &item)const;
    int Search(const T &item)const;
    void InsertFromHead()const;
    void InsertFromTail()const;
    bool DeleteFromHead()const;
    bool DeleteFromTail()const;
    void Insert(int index, T &item)const;
    void Delete(int index, T &item)const;
    void ShowMember();
};
template <typename T>
SList<T>::SList()
    :size(0)
{
    head = tail = currptr = new SLNode<T>();
}
template <typename T>
SList<T>::SList(const T &item)
    :size(1)
{
    head = tail = currptr = new SLNode<T>(item);
}
template <typename T>
SList<T>::~SList()
{
    SLNode<T> *temp;
    while(!IsEmpty()){
        temp = head->Next;
        head->Next = temp->Next;
        delete temp;
    }
}
template <typename T>
bool SList<T>::IsEmpty()const
{
    return head->Next == nullptr;
}
template <typename T>
int SList<T>::Length()const
{
    return size;
}
template <typename T>
bool SList<T>::Find(int index, const T &item)const
{
    if (index < 0){
        return false;
    }
    SLNode<T> *temp = head;
    if (temp == nullptr){
        return false;
    }
    int i = 0;
    while(temp != nullptr){
        if (i == index)
            break;
        temp = temp->Next;
        i++;
    }
    if (temp = nullptr){
        return false;
    }
    item = temp->data;
    return true;
}
template <typename T>
int SList<T>::Search(const T &item)
{
    SLNode<T> *temp;
    temp = head;
    int i = 0;
    while(temp != nullptr){
        if (item == temp->data)
            break;
        temp = temp->Next;
        i++;
    }
    if (temp == nullptr)
        return -1;
    return i;
}
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
