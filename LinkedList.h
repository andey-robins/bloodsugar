#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Node.h"

class List {
public:
    List();
    ~List();

    bool isEmpty() const;
    float removeFirst();

private:
    Node *first;
};

#endif
