#include "volsort.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List() : size(0), head(nullptr) {}

List::~List()
{
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
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
    head = newNode; // Set the new node as the head
    size++; // Increment the size
}

bool List::node_number_compare(const Node *a, const Node *b)
{
    return a->number < b->number;
}

bool List::node_string_compare(const Node *a, const Node *b)
{
    return a->str < b->str;
}