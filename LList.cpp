#include <iostream>

 #include "LList.h"


 //constructor
 LList::LList() {
     head = nullptr;
 }


 //copy constructor (iterative)
/*
 LList::LList(const LList& list) {
     head = nullptr;
     Node* other = list.head;
     Node* current = head;
     while (other != nullptr) {
         current = cons(other->item, nullptr);
         current = current->next;
         other = other->next;
     }
 }
*/

 //copy constructor using static itCopy (iterative)
 LList::LList(const LList& list) {
     head = itCopy(list.head);
 }


 //destructor
 LList::~LList() {
		deleteList();
 }

void LList::deleteList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

//assignment overload
LList& LList::operator = (const LList& rtSide) {
	if (this != &rtSide) {
        deleteList();
        head = itCopy(rtSide.head);
	}
	return *this;
 }

bool LList::isEmpty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

int LList::length() const {
	return length(head);
}

bool LList::cons(char ch){
	try {
		if (head == nullptr) {
			head = cons(ch, nullptr);
		}
		else {
			head = cons(ch, head);
		}
		return true;
	}
	catch (const std::bad_alloc&) {
		return false;
	}

}

bool LList::append(char ch) {
	try {
		if (head == nullptr) {
			head = cons(ch, nullptr);
		}
		else {
			Node * current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = cons(ch, nullptr);
		}
		return true;
	}
	catch (const std::bad_alloc&) {
		return false;
	}
}

bool LList::remove(char ch) {
	if (head == nullptr) {
		return false;
	}
	else if (head->item == ch) {
		Node* discard = head;
		head = head->next;
		delete discard;
		return true;
	}
	Node* current = head;
	Node* previous = head;

	while (current != nullptr) {
		if (current->item == ch) {
			previous->next = current->next;
			delete current;
			return true;
		}
		previous = current;
		current = current->next;

	}
	return false;
}

bool LList::found(char ch) const {
	Node* current = head;
	while (current != nullptr) {
		if (current->item == ch) {
			return true;
		}
		current = current->next;
	}
	return false;
}

char LList::getFirst(bool& hasFirst) const {
	if (head == nullptr) {
		hasFirst = false;
		return '\0';
	}
	hasFirst = true;
	return head->item;
}

void LList::reverse() {
	Node* current = head;
	Node* next = nullptr;
	Node* previous = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

void LList::print() const {
	std::cout << "[ ";
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->item << " ";
		current = current->next;
	}
	std::cout << "]\n";

}

int LList::length(Node *p) {
	if (p == nullptr) {
		return 0;
	}
	int counter = 1;
	Node* nextNode = p->next;
	while (nextNode != nullptr) {
		nextNode = nextNode->next;
		counter++;
	}
	return counter;
}

LList::Node* LList::cons(char ch, Node*p) {
	return new Node{ ch, p };
}

LList::Node* LList::itCopy(Node* p) {
    Node* start = nullptr;
    Node* current = start;
    Node* other = p;
    while (other != nullptr) {
        current = cons(other->item, nullptr);
        current = current->next;
        other = other->next;
    }
    return start;
}
