#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // head->data = 1;
    head->next = second;

    // second->data = 2;
    second->next = third;

    // third->data = 3;
    third->next = nullptr;

    printList(head);

    return 0;
}