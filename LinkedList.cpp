//
//  Code by Jacob "Andey" Tuttle
//  Last Update October 24, 2018
//  Liscenced under Mozilla Public Liscence 2.0
//

#include "LinkedList.h"

//
//  CONSTRUCTORS AND DESTRUCTORS FOLLOW
//
List::List(){
    first = NULL;
    overflow = 0;
}

List::~List(){
  while (!isEmpty()) {
	   removeFirst();
	}
}

//
//  LIST MUTIBLE FUNCTIONS FOLLOW
//
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

//
//  DATA PROCESSING FUNCTIONS FOLLOW
//
//return the sum of all items in the list
float List::sum() {

    if (first == NULL) {
        return 0.f;
    } else if (first->next == NULL) {
        return first->value;
    } else {
        float sum = first->value;
        Node* nextPtr = first->next;

        while (nextPtr != NULL) {
            if (std::numeric_limits<float>::max() - nextPtr->value < sum) {
                float temp = std::numeric_limits<float>::max() - sum;
                temp = nextPtr->value - temp;
                overflow++;
                sum = temp;
            } else {
                sum += nextPtr->value;
            }
            nextPtr = nextPtr->next;
        }

        return sum;
    }

}

//return the max value in the list
float List::max() const {

    if (first == NULL) {
        return 0.f;
    } else if (first->next == NULL) {
        return first->value;
    } else {
        float max = first->value;
        Node* nextPtr = first->next;

        while (nextPtr != NULL) {
            if (nextPtr->value > max) {
                max = nextPtr->value;
            }
            nextPtr = nextPtr->next;
        }

        return max;
    }
}

//return the min value in the list
float List::min() const {

    if (first == NULL) {
        return 0.f;
    } else if (first->next == NULL) {
        return first->value;
    } else {
        float min = first->value;
        Node* nextPtr = first->next;

        while (nextPtr != NULL) {
            if (nextPtr->value < min) {
                min = nextPtr->value;
            }
            nextPtr = nextPtr->next;
        }

        return min;
    }
}

//returnt the number of entries in the list
int List::count() const {

    if (first == NULL) {
        return 0;
    } else if (first->next == NULL) {
        return 1;
    } else {
        int count = 1;
        Node* nextPtr = first->next;

        while (nextPtr != NULL) {
            count++;
            nextPtr = nextPtr->next;
        }

        return count;
    }
}
