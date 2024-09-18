#include "volsort.h"
#include <iostream>

using namespace std;

// Prototypes
Node *qsort(Node *head, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

void quick_sort(List &l, bool numeric)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }
    l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *pivot = head;
    Node *left = nullptr;
    Node *right = nullptr;

    partition(head->next, pivot, left, right, numeric);

    left = qsort(left, numeric);
    right = qsort(right, numeric);

    pivot->next = right;
    return concatenate(left, pivot);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric)
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