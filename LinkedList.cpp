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
	Node* tempPtr = first;
	first = first->next;
	delete tempPtr;
	return item;
}

bool List::isEmpty() const {
    return first == NULL;
}

void List::addData(float x) {

  if (first == NULL){
    first = new Node(x, first);

  } else {
		Node* newEntry = new Node(x);
		Node* ptr = first;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newEntry;
  }

  return;
}

//return the sum of all items in the list
float List::sum() const {

    if (first == NULL) {
        return 0.f;
    } else if (first->next == NULL) {
        return first->value;
    } else {
        float sum = first->value;
        Node* nextPtr = first->next;

        while (nextPtr != NULL) {
            sum += nextPtr->value;
            nextPtr = nextPtr->next;
        }

        return sum;
    }

}
