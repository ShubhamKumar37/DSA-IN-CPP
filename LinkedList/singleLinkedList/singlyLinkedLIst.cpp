#include<IOSTREAM>

using namespace std;

class Node 
{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this -> data = data;
            this -> next = nullptr;
        }
};

void insertAtFirst(Node* &head, Node* &tail, int value)
{
    Node* newNode = new Node(value);
    if(head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
}

void traverseList(Node* &head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    if(head == nullptr && tail == nullptr)
    {   
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        tail = newNode;
    }
}

int main()
{
    // Node* first = new Node(34);

    // cout << first -> data << " - " << first -> next << endl;

    Node* head = nullptr;
    Node* tail = nullptr;

    // insertAtFirst(head, tail, 10);
    // insertAtFirst(head, tail, 20);
    // insertAtFirst(head, tail, 30);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);

    traverseList(head);
    cout << head -> data << endl;


    return 0;
}