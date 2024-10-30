#include<IOSTREAM>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }

};

void travere(Node* &head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout << temp -> data << " <-> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int lengthLL(Node* &head)
{
    Node* temp = head;
    int count = 0;
    while(temp != nullptr)
    {
        count++;
        temp = temp -> next;
    }

    return count;
}

void insertAtFirst(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int index, int data)
{
    if(index == 0 || head == nullptr)
    {
        insertAtFirst(head, tail, data);
    }
    else
    {
        int count = 0;
        Node* temp = head;

        while(count < index - 1 && temp != nullptr)
        {
            temp = temp -> next;
            ++count;
        }

        if(temp == nullptr || temp -> next == nullptr)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            Node* newNode = new Node(data);
            newNode -> next = temp -> next;
            newNode -> next -> prev = newNode;
            newNode -> prev = temp;
            temp -> next = newNode;
        }
    }
}

void deleteAtFirst(Node* &head, Node* &tail)
{
    if(head == nullptr) return ;
    else
    {
        if(head -> next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
            return ; 
        }

        Node* temp = head;
        head = temp -> next;
        head -> prev = nullptr;
        temp -> next = nullptr;

        delete temp;
    }
}

void deleteFromTail(Node* &head, Node* &tail)
{
    if(head == nullptr) return ;
    else
    {
        if(head -> next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
            return ; 
        }

        Node* currNode = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        currNode -> prev = nullptr;
        currNode = nullptr;
        
        delete currNode;

    }
}

void deleteFromPosition(Node* &head, Node* &tail, int index)
{
    if(head == nullptr) return ;
    else
    {
        if(index == 0 || head -> next == nullptr)
        {
            deleteAtFirst(head, tail);
            return ;
        }

        int count = 0;
        Node* temp = head;

        while(temp != nullptr && count < index - 1)
        {
            temp = temp -> next;
            ++count;
        }

        if(temp == nullptr || temp -> next == nullptr) return ;
        if(temp -> next -> next == nullptr)
        {
            deleteFromTail(head, tail);
            return ;
        }

        Node* removingNode = temp -> next;
        temp -> next = removingNode -> next;
        temp -> next -> prev = temp;

        removingNode -> next = nullptr;
        removingNode -> prev = nullptr;

        delete removingNode;
    }
}

bool searchTarget(Node* &head, int target)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        if(temp -> data == target) return true;
        temp = temp -> next;
    }

    return false;
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtFirst(head, tail, 40);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    insertAtFirst(head, tail, 30);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;
    
    insertAtTail(head, tail, 50);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    insertAtPosition(head, tail, 0, 20);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    insertAtPosition(head, tail, 0, 10);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;
    
    insertAtPosition(head, tail, 1, 70);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;
    
    insertAtPosition(head, tail, 5, 80);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    insertAtPosition(head, tail, 7, 90);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    insertAtPosition(head, tail, 27, 100);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    deleteAtFirst(head, tail);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    deleteFromTail(head, tail);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;

    deleteFromPosition(head, tail, 0);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;
 
    deleteFromPosition(head, tail, 1);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;
 
    deleteFromPosition(head, tail, 6);
    travere(head);
    cout << "Length = " << lengthLL(head) << endl;
 
    // deleteFromPosition(head, tail, 10);
    // travere(head);
    // cout << "Length = " << lengthLL(head) << endl;
 
    // cout << "Head = " << head -> data << " Tail = " << tail -> data << endl;
    if(searchTarget(head, 40))
    {
        cout << "Target is present in linked list" << endl;
    }
    else cout << "Target is not present in linked list" << endl;

    return 0;
}