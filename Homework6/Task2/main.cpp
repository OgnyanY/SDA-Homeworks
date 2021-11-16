#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Node {
    int id;
    int x;
    int y;
    Node *left;
    Node *right;

    Node(int id = 0, int x = 0, int y = 0) {
        this->id = id;
        this->x = x;
        this->y = y;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node *root;
    std::queue<Node *> nextElement;//unvisited elements
    std::stack<int> leftVisible;
    std::queue<int> rightVisible;

    //method to insert element
    Node *insert(Node *currentNode, int newLeft, int newRight) {
        if (currentNode == nullptr) {
            return currentNode;
        }

        if (newLeft != -1) {
            currentNode->left = new Node(newLeft, currentNode->x - 1, currentNode->y - 1);
            nextElement.push(currentNode->left);
        }
        if (newRight != -1) {
            currentNode->right = new Node(newRight, currentNode->x + 1, currentNode->y - 1);
            nextElement.push(currentNode->right);
        }
        nextElement.pop();

        return currentNode;
    }

    //method to print tree by top view
    void printTopView(Node *rootNode) {
        if (!rootNode) {
            return;
        }

        int currentMin = 0;
        int currentMax = 0;

        //findVisible(rootNode->left, rootNode->right, currentMin, currentMax);

        findMin(rootNode->left, currentMin);
        while (!leftVisible.empty()) {
            std::cout << leftVisible.top() << ' ';
            leftVisible.pop();
        }
        std::cout << root->id << ' ';
        findMax(rootNode->right, currentMax);
        while (!rightVisible.empty()) {
            std::cout << rightVisible.front() << ' ';
            rightVisible.pop();
        }

    }

    /*Node* findVisible(Node *left, Node *right, int& currentMin, int& currentMax) {
        if (left == nullptr || right == nullptr) {
            return nullptr;
        }
        if (left->x < currentMin) {
            currentMin = left->x;
            leftVisible.push(left->id);
        }
        if (right->x > currentMax) {
            currentMax = right->x;
            rightVisible.push(right->id);
        }

        if (left->left != nullptr) {
            return findMin(left->left, currentMin);
        } else if (left->right != nullptr) {
            return findMin(left->right, currentMin);
        }


        if (right->right != nullptr) {
            return findMax(right->right, currentMax);
        } else if (right->left != nullptr) {
            return findMax(right->left, currentMax);
        }
    }*/


    Node *findMin(Node *rootNode, int &currentMin) {
        if (rootNode == nullptr) {
            return nullptr;
        }
        if (rootNode->x < currentMin) {
            currentMin = rootNode->x;
            leftVisible.push(rootNode->id);
        }
        if (rootNode->left != nullptr) {
            return findMin(rootNode->left, currentMin);
        } else if (rootNode->right != nullptr) {
            return findMin(rootNode->right, currentMin);
        } else {
            return rootNode;
        }
    }

    Node *findMax(Node *rootNode, int &currentMax) {
        if (rootNode == nullptr) {
            return nullptr;
        }
        if (rootNode->x > currentMax) {
            currentMax = rootNode->x;
            rightVisible.push(rootNode->id);
        }
        if (rootNode->right != nullptr) {
            return findMax(rootNode->right, currentMax);
        } else if (rootNode->left != nullptr) {
            return findMax(rootNode->left, currentMax);
        } else {
            return rootNode;
        }
    }

public:
    BinarySearchTree() {
        root = new Node();
        nextElement.push(root);
    }

    //method to insert element
    void insert(int newLeft, int newRight) {
        if (root == nullptr) {
            root = new Node();
        } else if (newLeft == -1 && newRight == -1) {
            nextElement.pop();
            return;
        } else {
            insert(nextElement.front(), newLeft, newRight);
        }
    }

    //method to print tree by level
    void printTopView() {
        printTopView(root);
    }
};

int main() {
    int operationsSize = 0;
    std::cin >> operationsSize;

    BinarySearchTree tree;

    for (int i = 0; i < operationsSize; ++i) {
        int left = 0;
        int right = 0;
        std::cin >> left >> right;
        tree.insert(left, right);
    }

    tree.printTopView();
}