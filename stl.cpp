#include "volsort.h"
#include <algorithm>
#include <vector>

using namespace std;

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
            sort(arr.begin(), arr.end(), node_number_compare);
        }
        else
        {
            sort(arr.begin(), arr.end(), node_string_compare);
        }

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            arr[i]->next = arr[i + 1];
        }
        arr.back()->next = nullptr;
        l.head = arr.front();
    }
}