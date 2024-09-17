// qsort.cpp

#include "volsort.h"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>

// Comparison function for numeric sorting (adapted for qsort)
int node_number_compare(const void *a, const void *b)
{
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    return (nodeA->number - nodeB->number);
}

// Comparison function for string sorting (adapted for qsort)
int node_string_compare(const void *a, const void *b)
{
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    return strcmp(nodeA->str.c_str(), nodeB->str.c_str());
}

void qsort_sort(List &l, bool numeric)
{
    // Convert the linked list into a vector of Node pointers
    std::vector<Node *> arr;
    Node *n = l.head;

    // Traverse the list and add each node to the vector
    while (n != NULL) // Use NULL instead of nullptr for C++98 compatibility
    {
        arr.push_back(n);
        n = n->next;
    }

    // Sort the vector using qsort
    if (numeric)
    {
        // Sort using number comparison
        qsort(&arr[0], arr.size(), sizeof(Node *), node_number_compare);
    }
    else
    {
        // Sort using string comparison
        qsort(&arr[0], arr.size(), sizeof(Node *), node_string_compare);
    }

    // Rebuild the linked list in the sorted order
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        arr[i]->next = arr[i + 1];
    }

    // Last element points to NULL
    arr.back()->next = NULL;

    // Update the head of the list
    l.head = arr.front();
}