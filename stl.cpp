// stl.cpp

#include "volsort.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric)
{
    Node *n = l.head;
    vector<Node> arr;
    while (n->next = nullptr)
    {
        arr.push_back(*n);
    }
    sort(arr.begin(), arr.end());
}
