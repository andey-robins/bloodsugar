//
//  Code by Jacob "Andey" Tuttle
//  Last Update October 8, 2018
//  Liscenced under Mozilla Public Liscence 2.0
//

#include "Node.h"

//Initializes a node w/ an empty pointer
Node::Node(float v){
    value = v;
    next = NULL;
}

//Initializes a node w/ a next value
Node::Node(float v, Node* n){
    value = v;
    next = n;
}

//Destructor
Node::~Node(){

}
