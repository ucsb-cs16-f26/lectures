#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to delete the entire linked list and free memory
void deleteList(Node *&head)
{
    Node *toDelete = nullptr; // Temporary pointer for the node to delete

    while (head) // Continue while the list is not empty
    {
        toDelete = head;   // Store the current head node
        head = head->next; // Move head to the next node
        delete toDelete;   // Free memory of the old head node
    }
}

void prepend(Node *&head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void printList(Node *head)
{
    if (!head)
    {
        cout << "The list is empty" << endl;
        return;
    }
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    prepend(head, 4);
    prepend(head, 8);
    prepend(head, 2);

    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}