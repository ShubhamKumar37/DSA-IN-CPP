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
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
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

int lengthLL(Node* head)
{
    Node* temp = head;
    int sum = 0;

    while(temp != nullptr)
    {
        sum++;
        temp = temp -> next;
    }

    return sum;
}

void insertAtLocation(Node* &head, Node* &tail, int index, int data)
{
    Node* newNode = new Node(data);
    if(index <= 0)
    {
        insertAtFirst(head, tail, data);
        return ;
    }
    else
    {
        int i = 0;
        Node* temp = head;
        while(temp != nullptr && i < index - 1)
        {
            temp = temp -> next;
            i++;
        }

        if(temp == nullptr || temp -> next == nullptr)
        {
            insertAtTail(head, tail, data);
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void deleteNode(Node* &head, Node* &tail, int index)
{
    int i = 0;
    Node* temp = head;

    if(head == nullptr) return ;
    else if(index == 0 || temp -> next == nullptr)
    {
        if(temp -> next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else head = temp -> next;

        temp = nullptr;
        delete temp;
        return ;
    }
    
    while(i < index - 1 && temp != nullptr)
    {
        temp = temp -> next;
        i++;
    }
    
    if(temp == nullptr || temp -> next == nullptr) return ;

    Node* deletingNode = temp -> next;
    temp -> next = temp -> next -> next;
    deletingNode = nullptr;

    delete deletingNode;

    if(temp -> next == nullptr) tail = temp;
}

int findTarget(Node* head, int target)
{
    Node* temp = head;
    int index = 0;

    while(temp != nullptr)
    {
        if(temp -> data == target) return index;
        temp = temp -> next;
        index++;
    }

    return -1;
}

int main()
{
    // Node* first = new Node(34);

    // cout << first -> data << " - " << first -> next << endl;

    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtFirst(head, tail, 10);
    insertAtFirst(head, tail, 20);
    insertAtFirst(head, tail, 30);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);

    traverseList(head);
    // cout << head -> data << endl;

    insertAtLocation(head, tail, 0, 100);
    // insertAtLocation(head, tail, 3, 100);
    // insertAtLocation(head, tail, 4, 300);
    // insertAtLocation(head, tail, 1, 1200);

    traverseList(head);

    cout << "Length of linked list = " << lengthLL(head) << endl;

    cout << "Find target = " << findTarget(head, 210) << endl;

    deleteNode(head, tail, 0);
    traverseList(head);
    deleteNode(head, tail, 1);
    traverseList(head);
    deleteNode(head, tail, 5);
    traverseList(head);
    deleteNode(head, tail, 4);
    traverseList(head);
    deleteNode(head, tail, 4);
    traverseList(head);
    deleteNode(head, tail, 0);
    traverseList(head);

    cout << "Head = " << head -> data << " Tail = " << tail -> data << endl;

    return 0;
}