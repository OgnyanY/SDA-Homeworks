#include <iostream>
#include <string>


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int nodeData,Node* prev = nullptr, Node* next = nullptr) {
        this->data = nodeData;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList {
public:
    Node* head = nullptr;
    Node* mid = nullptr;
    Node* tail = nullptr;

    DoublyLinkedList()  = default;

    void pushNodeBack(int nodeData, int adds) {
        Node* node = new Node(nodeData);
        if (!this->head) {//no elements in the list
            this->head = node;
            this->head->prev = nullptr;
            this->mid = this->head;
            this->tail = this->head;
        }
        else {//there is elements in the list
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = this->tail->next;

            //consider the middle of the list
            if(adds > 2 && adds % 2 == 0) {
                this->mid = this->mid->next;
            }
        }
    }

    void popNodeBack(int adds) {
        if (this->head) {//if there is elements to remove
            if (this->head == this->tail) {//remove the last element
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->mid = nullptr;
            }
            else {
                // delete the tail and point tail to the previous node
                Node* prev = this->tail->prev;
                delete this->tail;
                prev->next = nullptr;
                this->tail = prev;

                //consider the middle of the list
                if(adds > 1 && adds % 2 != 0) {
                    this->mid = this->mid->prev;
                }
            }
        }
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

void shuffleTests(DoublyLinkedList* list, int adds) {
    //save the elements that I am using to shuffle the list
    Node* oldHead = list->head;
    Node* oldTail = list->tail;
    Node* newHead = list->mid->next;
    Node* newTail = list->mid;

    //this will be the new head
    list->mid->next->prev = nullptr;
    //this will be the new tail
    list->mid->next = nullptr;
    //update new head
    newHead->prev = nullptr;

    //shuffle the list
    oldHead->prev = list->tail;
    oldTail->next = list->head;

    //find new mid
    if(adds % 2 != 0) {
        list->mid = oldTail->prev;
    }
    else{
        list->mid = oldTail;
    }
    //new head and tail
    list->head = newHead;
    list->tail = newTail;
}

int main() {
    auto* list = new DoublyLinkedList();
    //all commands
    int commands;
    std::cin >> commands;

    int command = 1;
    int adds = 0;//elements in the list

    while (command <= commands) {
        std::string str;
        std::cin >> str;

        if(str == "add") {//if str is "add" continue
            continue;
        }
        else if(str == "gun") {//if str is "gun" remove element from back
            if(adds == 0){//guardian
                ++command;
                continue;
            }
            list->popNodeBack(adds - 1);
            --adds;
            ++command;
        }
        else if(str == "milen") {//if str is "milen" shuffle the list
            if(adds < 2){//guardian
                ++command;
                continue;
            }
            shuffleTests(list,adds);
            ++command;
        }
        else {//if str is number, add it to list
            list->pushNodeBack(stoi(str),adds + 1);
            ++adds;
            ++command;
        }
    }
    std::cout << adds << '\n';
    list->print();

    return 0;
}