//
//  Code by Jacob "Andey" Tuttle
//  Last Update October 24, 2018
//  Liscenced under Mozilla Public Liscence 2.0
//

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Node.h"

class List {
public:
    List();
    ~List();

    bool isEmpty() const;
    float removeFirst();
    void addData(float x);

    float sum() const;
    float max() const;
    float min() const;
    int count() const;

    Node *first;
    int day;
};

#endif
