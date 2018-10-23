#include "LinkedList.h"

List::List(){
    first = NULL;
}

List::~List(){
    while (!empty()) {
		removeFirst();
	}
}

bool List::isEmpty() const {
    return first == NULL;
}
