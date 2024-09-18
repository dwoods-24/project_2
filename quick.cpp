#include "volsort.h"
#include <iostream>

using namespace std;

// Prototypes
Node *qsort(Node *head, bool numeric, List &dummy);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric, List &dummy);
Node *concatenate(Node *left, Node *right);

void quick_sort(List &l, bool numeric)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }
    l.head = qsort(l.head, numeric, l);
}

Node *qsort(Node *head, bool numeric, List &dummy)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *pivot = head;
    Node *left = nullptr;
    Node *right = nullptr;

    partition(head->next, pivot, left, right, numeric, dummy);

    left = qsort(left, numeric, dummy);
    right = qsort(right, numeric, dummy);

    pivot->next = right;
    return concatenate(left, pivot);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric, List &dummy)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        if ((numeric && node_number_compare(current, pivot)) ||
            (!numeric && node_string_compare(current, pivot)))
        {
            current->next = left;
            left = current;
        }
        else
        {
            current->next = right;
            right = current;
        }
        current = next;
    }
}

Node *concatenate(Node *left, Node *right)
{
    if (left == nullptr)
        return right;
    Node *temp = left;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = right;
    return left;
}