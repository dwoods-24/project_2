// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>
#include <iostream>
using namespace std;

struct Node
{
  string str;
  int number;
  Node *next;
};

struct List
{
  Node *head;
  size_t size;

  List();  // define in list.cpp
  ~List(); // define in list.cpp

  bool node_number_compare(const Node *a, const Node *b); // implement in list.cpp to avoid compile-time issues, used by quick, merge and stl
  bool node_string_compare(const Node *a, const Node *b); // implement in list.cpp to avoid compile-time issues, merge and stl
  void push_front(const string &s);                       // define below
  void dump_node(Node *n)
  {
    do
    {
      cout << n->number << endl;
      n = n->next;
    } while (n->next != nullptr);

  }; // implement in this file (volsort.h) to make it easier for TAs to grade
};

// Functions -------------------------------------------------------------------

void stl_sort(List &l, bool numeric);   // define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric); // define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric); // define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric); // define in quick.cpp - your implementation

#endif
