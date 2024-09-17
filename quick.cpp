#include "volsort.h"

#include <iostream>

// Prototypes

// Node *qsort(Node *head, bool numeric) 
// void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
// Node *concatenate(Node *left, Node *right);


void quick_sort(List &l, bool numeric) {
    if (l.head == nullptr || l.head->next == nullptr) {
        // List is empty or has one element, no need to sort
        return;
    }
    l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: single node or empty list
    }

    Node *pivot = head; // Choose the pivot (could be any node)
    Node *left = nullptr;
    Node *right = nullptr;
    
    partition(head->next, pivot, left, right, numeric); // Partition the list

    left = qsort(left, numeric); // Recursively sort the left sublist
    right = qsort(right, numeric); // Recursively sort the right sublist

    // Concatenate the sorted sublists with the pivot
    return concatenate(left, concatenate(pivot, right));
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        if ((numeric && current->number < pivot->number) || 
            (!numeric && current->number < pivot->number)) {
            current->next = left;
            left = current;
        } else {
            current->next = right;
            right = current;
        }
        current = next;
    }
    // Ensure the end of the lists are terminated
    if (left != nullptr) {
        Node *temp = left;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
    if (right != nullptr) {
        Node *temp = right;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
}

Node *concatenate(Node *left, Node *right) {
    if (left == nullptr) return right;
    Node *temp = left;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = right;
    return left;
}

