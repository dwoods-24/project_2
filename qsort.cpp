// qsort.cpp

#include "volsort.h"
#include <cstdlib>
#include <vector>
#include <iostream>

// Wrapper functions for qsort
int node_number_compare_wrapper(const void *a, const void *b)
{
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    if (nodeA->number < nodeB->number)
        return -1;
    if (nodeA->number > nodeB->number)
        return 1;
    return 0;
}

int node_string_compare_wrapper(const void *a, const void *b)
{
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    return nodeA->str.compare(nodeB->str);
}

void qsort_sort(List &l, bool numeric)
{

    std::vector<Node *> arr;
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

        l.head = arr[0];
        for (size_t i = 0; i < arr.size() - 1; ++i)
        {
            arr[i]->next = arr[i + 1];
        }
        arr.back()->next = nullptr;
        l.size = arr.size();
    }
    else
    {
        l.head = nullptr;
        l.size = 0;
    }
}