#include "volsort.h"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

// Wrapper functions for qsort
int node_number_compare_wrapper(const void *a, const void *b)
{
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    List dummy; // Dummy list to access the comparison function
    return dummy.node_number_compare(nodeA, nodeB) ? -1 : 1;
}

int node_string_compare_wrapper(const void *a, const void *b)
{
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    List dummy; // Dummy list to access the comparison function
    return dummy.node_string_compare(nodeA, nodeB) ? -1 : 1;
}

void qsort_sort(List &l, bool numeric)
{
    vector<Node *> arr;
    Node *n = l.head;

    while (n != nullptr)
    {
        arr.push_back(n);
        n = n->next;
    }

    if (!arr.empty())
    {
        if (numeric)
        {
            qsort(&arr[0], arr.size(), sizeof(Node *), node_number_compare_wrapper);
        }
        else
        {
            qsort(&arr[0], arr.size(), sizeof(Node *), node_string_compare_wrapper);
        }

        for (size_t i = 0; i < arr.size() - 1; ++i)
        {
            arr[i]->next = arr[i + 1];
        }
        arr.back()->next = nullptr;
        l.head = arr.front();
    }
}