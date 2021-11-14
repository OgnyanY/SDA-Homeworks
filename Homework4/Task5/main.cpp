#include <iostream>
#include <sstream>
#include <vector>

class Node {
public:
    int data;
    int index;
    Node* next;
    Node* prev;

    Node(int data, int idNumber)
            : data(data), index(idNumber), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    Node *head;
    Node *tail;

public:
    // Vector to hold the addresses of all Nodes(Balls)
    std::vector<Node *> ids;

    DoublyLinkedList() = default;

    void pushNodeBack(int data, int index) {
        Node* node = new Node(data,index);
        if (!this->head) {//no elements in the list
            this->head = node;
            this->head->prev = nullptr;
            this->tail = this->head;
            ids.push_back(node);
        }
        else {//there is elements in the list
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = this->tail->next;
            ids.push_back(node);
        }
    }

    void insertNote_atPos(int position, int data, int index) {
        Node* newNode = new Node(data, index);
        ids.push_back(newNode);

        //the address of the element that needs to be inserted after
        Node* insertionPos = ids[position];

        //if the new element needs to be inserted after tail, insert it after tail,
        if (insertionPos == tail) {
            insertionPos->next = newNode;
            newNode->prev = insertionPos;
            tail = newNode;
            return;
        }

        // Insert the new element between the pointer of 'insertionPos' and its next
        Node* nextElement = insertionPos->next;
        nextElement->prev = newNode;
        newNode->next = nextElement;

        insertionPos->next = newNode;
        newNode->prev = insertionPos;
    }
};

int main (){
    int ballsCount;
    std::cin >> ballsCount;
    // Filling the list with the first elements
    auto* list = new DoublyLinkedList();
    int color;
    for (int i = 0; i < ballsCount; i++) {
        std::cin >> color;
        list->pushNodeBack(color, i);
    }
}