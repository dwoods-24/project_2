#include "volsort.h"
#include <iostream>

using namespace std;

// Prototypes
Node *msort(Node *head, bool numeric, List &dummy);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric, List &dummy);

void merge_sort(List &l, bool numeric)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }
    l.head = msort(l.head, numeric, l);
}

Node *msort(Node *head, bool numeric, List &dummy)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *left, *right;
    split(head, left, right);

    left = msort(left, numeric, dummy);
    right = msort(right, numeric, dummy);

    return merge(left, right, numeric, dummy);
}

void split(Node *head, Node *&left, Node *&right)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    left = head;
    right = slow->next;
    slow->next = nullptr;
}

Node *merge(Node *left, Node *right, bool numeric, List &dummy)
{
    Node temporaryNode;
    Node *tail = &temporaryNode;

    while (left != nullptr && right != nullptr)
    {
        bool compareResult;
        if (numeric)
        {
            compareResult = node_number_compare(left, right);
        }
        else
        {
            compareResult = node_string_compare(left, right);
        }

        if (compareResult)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = (left != nullptr) ? left : right;

    return temporaryNode.next;
}