#include "volsort.h"
#include <algorithm>
#include <vector>

using namespace std;

// Wrapper functions for std::sort
struct NodeNumberCompare {
    bool operator()(const Node* a, const Node* b) const {
        List dummy;
        return dummy.node_number_compare(a, b);
    }
};

struct NodeStringCompare {
    bool operator()(const Node* a, const Node* b) const {
        List dummy;
        return dummy.node_string_compare(a, b);
    }
};

void stl_sort(List &l, bool numeric)
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
            sort(arr.begin(), arr.end(), NodeNumberCompare());
        }
        else
        {
            sort(arr.begin(), arr.end(), NodeStringCompare());
        }

        for (size_t i = 0; i < arr.size() - 1; ++i)
        {
            arr[i]->next = arr[i + 1];
        }
        arr.back()->next = nullptr;
        l.head = arr.front();
    }
}