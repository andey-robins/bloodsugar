//
//  Code by Jacob "Andey" Tuttle
//  Last Update October 23, 2018
//  Liscenced under Mozilla Public Liscence 2.0
//

#ifndef NULL
#define NULL (0)
#endif

#ifndef _NODE_H_
#define _NODE_H_

class Node{

//values of the Node
public:
    float value;
    Node *next;

//functions for the node
public:
    //constructors
    Node(float v);

    Node(float v, Node* n);

    //destructors
    ~Node();

};

#endif
