#include "LinkedList.h"

List::List(){
    first = NULL;
}

List::~List(){
    while (!isEmpty()) {
		removeFirst();
	}
}

float List::removeFirst() {
    float item = first->value;
	Node * tempPtr = first;
	first = first->next;
	delete tempPtr;
	return item;
}

bool List::isEmpty() const {
    return first == NULL;
}
