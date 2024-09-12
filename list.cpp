#include "volsort.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List() : size(0), head(nullptr) // Constructor
{};

List::~List() // Destructor
{
    delete this;
}

//---Functions------------------------------------------------
void List::push_front(const string &s) // define below
{
    Node *newNode = new Node();
    newNode->next = head;
    newNode->str = s;
    newNode->number = stoi(s);
};
bool node_number_compare(const Node *a, const Node *b)
{
    if (a->number == a->number)
    {
        return true;
    }
    else
    {
        return false;
    }
};
bool node_string_compare(const Node *a, const Node *b)
{
    if (a->str == a->str)
    {
        return true;
    }
    else
    {
        return false;
    }
};
