// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>

// C++98 style comparison function for numeric sorting
bool node_number_compare(const Node *a, const Node *b)
{
    return a->number < b->number;
}

// C++98 style comparison function for string sorting
bool node_string_compare(const Node *a, const Node *b)
{
    return a->str < b->str;
}

void qsort_sort(List &l, bool numeric) {
    // Convert the linked list into a vector of Node pointers
    vector<Node *> arr;
    Node *n = l.head;

    // Traverse the list and add each node to the vector
    while (n != nullptr)
    {
        arr.push_back(n);
        n = n->next;
    }

    // Sort the vector based on the numeric flag
    if (numeric)
    {
        // Sort using number comparison
        qsort(arr.begin(), arr.end(), node_number_compare);
    }
    else
    {
        // Sort using string comparison
        qsort(arr.begin(), arr.end(), node_string_compare);
    }

    // Rebuild the linked list in the sorted order
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        arr[i]->next = arr[i + 1];
    }

    // Last element points to nullptr
    arr.back()->next = nullptr;

    // Update the head of the list
    l.head = arr.front();
}

