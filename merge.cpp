#include "volsort.h"
#include<iostream>
// Prototypes

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Static comparison functions
static bool compare_nodes(const Node *a, const Node *b, bool numeric) {
    if (numeric) {
        return a->number < b->number;
    } else {
        return a->str < b->str;
    }
}

// Implementations

void merge_sort(List &l, bool numeric) {
    if (l.head == nullptr || l.head->next == nullptr) {
        return; // List is empty or has only one element
    }
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: list is empty or has only one element
    }

    Node *left, *right;
    split(head, left, right);

    // Recursively sort the sublists
    left = msort(left, numeric);
    right = msort(right, numeric);

    // Merge the sorted sublists
    return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right) {
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    left = head;
    right = slow->next;
    slow->next = nullptr;
}

Node *merge(Node *left, Node *right, bool numeric) {
    Node empty; // Dummy node to simplify the merging process
    Node *tail = &empty;

    while (left != nullptr && right != nullptr) {
        if (compare_nodes(left, right, numeric)) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes
    tail->next = (left != nullptr) ? left : right;

    return empty.next;
}