// qsort.cpp

#include "volsort.h"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <functional>

int compare(const void *a, const void *b)
{
    int *intA = (int *)a;
    int *intB = (int *)b;

    if (*intA < *intB)
    {
        return -1; // a is less than b
    }
    else if (*intA > *intB)
    {
        return 1; // a is greater than b
    }
    else
    {
        return 0; // a is equal to b
    }
}

void qsort_sort(List &l, bool numeric)
{
    // Convert the linked list into a vector of Node pointers
    vector<Node *> arr;
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
        qsort(arr.data(), arr.size(), sizeof(Node *), compare);
    }
    else
    {
        // Sort using string comparison
        qsort(arr.data(), arr.size(), sizeof(Node *), compare);
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
