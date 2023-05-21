#include <iostream>

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node() : data(0), prev(NULL), next(NULL) {}
        Node(int digit) : data(digit), prev(NULL), next(NULL) {}
        ~Node() {
            prev = NULL;
            next = NULL;
        }

        bool operator==(Node* element) {
            return data == element->data;
        }
};

class linkedList {
    Node* element = NULL;

    public:
        linkedList(int digit) {
            element = new Node(digit);
        }

        linkedList() {}

        bool atEnd() {
            bool _end = false;
            if (element->next == NULL) {
                _end = true;
            }
            return _end;
        }

        bool atStart() {
            bool _start = false;
            if (element->prev == NULL) {
                _start = true;
            }
            return _start;
        }

        void start() {
            while (!atStart()) {
                goPrev();
            }
        }

        void end() {
            while (!atEnd()) {
                goNext();
            }
        }

        void goPrev() {
            if (!atStart()) {
                element = element->prev;
            }
        }

        void goNext() {
            if (!atEnd()) {
                element = element->next;
            }
        }

        void append(int digit) {
            if (element == NULL) {
                element = new Node(digit);
            } else {
                end();
                Node* new_element = new Node(digit);
                element->next = new_element;
                new_element->prev = element;
            }
        }

        Node* getElement() {
            return element;
        }

        void cycleToIndex(int index) {
            start();
            int i = 0;
            while (i < index) {
                goNext();
                i++;
            }
        }

        Node& operator[](int index) {
            cycleToIndex(index);
            return *getElement();
        }

        void clearElement() {
            if (element) {
                element;
                element = NULL;
            }
        }

        void remove(int index) {
            cycleToIndex(index);
            if (atStart() && atEnd()) {
                clearElement();
            } else if (atStart()) {
                Node* temp_element = element->next;
                clearElement();
                element = temp_element;
                element->prev = NULL;
            } else if (atEnd()) {
                Node* temp_element = element->prev;
                clearElement();
                element = temp_element;
                element->next = NULL;
            } else {
                element->prev->next = element->next;
                element->next->prev = element->prev;
                Node* temp_element = element;
                clearElement();
                element = temp_element->next;
            }
        }

        void insert(int digit) {
            Node* new_element = new Node(digit);
            if (element == NULL) {
                element = new_element;
            } else {
                if (!atStart()) {
                    new_element->prev = element->prev;
                    element->prev->next = new_element;
                }
                element->prev = new_element;
                new_element->next = element;
            }
        }

        void cycleThroughList() {
            start();
            while (!atEnd()) {
                std::cout << element->data << std::endl;
                goNext();
            }
            std::cout << element->data << std::endl;
        }
};


int main() {
    linkedList list(1);
    list.remove(0);
    list.append(2);
    list.append(3);
    list.cycleThroughList();
    std::cout << std::endl;
    list.remove(2);
    list.cycleThroughList();
}