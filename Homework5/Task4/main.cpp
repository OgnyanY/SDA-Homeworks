#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int nodeData,Node* prev = nullptr, Node* next = nullptr) {
        this->data = nodeData;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    DoublyLinkedList()  = default;

    void pushNodeBack(int nodeData) {
        Node* node = new Node(nodeData);
        if (!this->head) {//no elements in the list
            this->head = node;
            this->head->prev = nullptr;
            this->tail = this->head;
        }
        else {//there is elements in the list
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = this->tail->next;
        }
    }

    void pushNodeFront(int nodeData) {
        Node* newHead = new Node(nodeData, nullptr, head);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void popBackNode() {
        if (this->head) {//if there is elements to remove
            if (this->head == this->tail) {//remove the last element
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            }
            else {
                // delete the tail and point tail to the previous node
                Node* prev = this->tail->prev;
                delete this->tail;
                prev->next = nullptr;
                this->tail = prev;
            }
        }
    }

    void popFrontNode() {
        if (head != nullptr) {
            Node* oldHead = head;
            if (tail == head) {
                tail = nullptr;
            }
            head = head->next;
            delete oldHead;
        } else {
            throw std::out_of_range("List is empty, cannot popFrontNode()");
        }
    }

    int getNode(int position) const {
        if (head == nullptr) {
            throw std::out_of_range("List is empty, cannot getNode from it");
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                current = current->next;
            } else {
                throw std::out_of_range("Cannot getNode from list, no such position");
            }
        }

        return current->data;
    }

    void removeNode(int position) {
        if (position == 0) {
            popFrontNode();
            return;
        }

        if (head == nullptr) {
            throw std::out_of_range("Invalid removeNode index, list is empty");
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                current = current->next;
            } else {
                throw std::out_of_range("Cannot insertAt in invalid position");
            }
        }

        current->prev->next = current->next;
        if(current->next){
            current->next->prev = current->prev;
        }
        if (tail == current) {
            tail = current->prev;
        }
        delete current;
    }

    void print() const {
        Node* node = head;
        while (node) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << '\n';
    }

};

int main() {
    int participantsSize = 0;
    std::cin >> participantsSize;
    DoublyLinkedList participants;

    for (int i = 0; i < participantsSize; ++i) {
        int participant = 0;
        std::cin >> participant;
        participants.pushNodeBack(participant);
    }

    Node *current = participants.tail->prev;
    int answer = 0;
    bool loseBattle = false;
    while(true){
        for (int j = participantsSize - 1; j > 0 ; j--) {
            if (current->next && current->next->data > current->data) {
                participants.removeNode(j);
                --participantsSize;
                loseBattle = true;
            }
            current = current->prev;
        }
        if(loseBattle){
            ++answer;
            loseBattle = false;
        }
        else {
            break;
        }
        current = participants.tail->prev;
    }
    std::cout << answer;
}