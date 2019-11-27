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
        Next = nextNode;
    }
};
template <typename T>
class SList{
private:
    SLNode<T> *head;
    SLNode<T> *tail;
    SLNode<T> *currptr;
    int size;
public:
    SList();
    SList(const T &item);
    ~SList();
    bool IsEmpty()const;
    int Length()const;
    bool Find(int index, const T &item)const;
    int Search(const T &item)const;
    void InsertFromHead(const T &item);
    void InsertFromTail(const T &item);
    bool DeleteFromHead(T &item);
    bool DeleteFromTail(T &item);
    void Insert(int index, const T &item);
    void Delete(int index, T &item);
    void ShowListMember();
};
template <typename T>
SList<T>::SList()
{
    head = tail = currptr = new SLNode<T>();
    size = 0;
}
template <typename T>
SList<T>::SList(const T &item)
{
    tail = currptr = new SLNode<T>(item);
    head = new SLNode<T>(currptr);
    size = 1;
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
    delete head;
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
    if (index < 1){
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
int SList<T>::Search(const T &item)const
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
template <typename T>
void SList<T>::InsertFromHead(const T&item)
{
    if (IsEmpty()){
        head->Next = new SLNode<T>(item, head->Next);
        tail = head->Next;
    }else{
        head->Next = new SLNode<T>(item, head->Next);
    }
    size++;
}

template <typename T>
void SList<T>::InsertFromTail(const T &item)
{
    tail->Next = new SLNode<T>(item, tail->Next);
    tail = tail->Next;
    size++;
}

template <typename T>
bool SList<T>::DeleteFromHead(T &item)
{
    if (IsEmpty()){
        cout<<"list is empty"<<endl;
        return false;
    }
    SLNode<T> *temp = head->Next;
    head->Next = temp->Next;
    item = temp->data;
    delete temp;
    size--;
    return true;
}

template <typename T>
bool SList<T>::DeleteFromTail(T &item)
{
    if (IsEmpty()){
        cout<<"list is empty"<<endl;
        return false;
    }
    SLNode<T> *temp = head;
    while(temp->Next != tail){
        temp = temp->Next;
    }
    item = tail->data;
    delete tail;
    tail = temp;
    tail->Next = nullptr;
    size--;
    return true;
}

template <typename T>
void SList<T>::Insert(int index, const T &item)
{
    SLNode<T> *temp = head;
    int i = 0;
    if (index < 1)index = 1;
    if (index > size)index = size;

    while(1){
        if (i == index-1)
            break;
        head = head->Next;
        i++;
    }
    InsertFromHead(item);
    head = temp;
}

template <typename T>
void SList<T>::Delete(int index, T &item)
{
    if (index < 1)index = 1;
    if (index > size)index = size;
    SLNode<T> *temp = head;
    int i = 0;
    while(1){
        if (i == index-1)
            break;
        head = head->Next;
        i++;
    }
    DeleteFromHead(item);
    head = temp;
}

template <typename T>
void SList<T>::ShowListMember()
{
    SLNode<T> *temp;
    temp = head->Next;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp = temp->Next;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    int item;
    SList<int> list;

    list.InsertFromTail(1);
    list.InsertFromTail(2);
    list.InsertFromTail(3);
    list.InsertFromTail(4);
    list.InsertFromTail(5);
    list.InsertFromTail(6);
    list.InsertFromTail(7);
    cout<<"list number:"<<list.Length()<<endl;
    list.ShowListMember();

    list.Insert(2,8);
    cout<<"list number:"<<list.Length()<<endl;
    list.ShowListMember();

    list.Delete(2,item);
    cout<<"list number:"<<list.Length()<<endl;
    list.ShowListMember();
    return 0;
}
