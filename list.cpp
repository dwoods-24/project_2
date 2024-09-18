#include "volsort.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List() : size(0), head(nullptr) {}

List::~List()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

void List::push_front(const string &s)
{
    Node *newNode = new Node();
    newNode->next = head;
    newNode->str = s;
    newNode->number = atoi(s.c_str()); // Use atoi instead of stoi for C++98
    head = newNode;                    // Set the new node as the head
    size++;                            // Increment the size
}

void dump_node(Node *n)
{
    do
    {
        cout << n->number << endl;
        n = n->next;
    } while (n->next != nullptr);

}; // implement in this file (volsort.h) to make it easier for TAs to grade

bool node_number_compare(const void *a, const void *b)
{
    const Node *arg1 = static_cast<const Node *>(a);
    const Node *arg2 = static_cast<const Node *>(b);
    return arg1->number < arg2->number;
}

bool node_string_compare(const void *a, const void *b)
{
    const Node *arg1 = static_cast<const Node *>(a);
    const Node *arg2 = static_cast<const Node *>(b);
    return arg1->str < arg2->str;
}