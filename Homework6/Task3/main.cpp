#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;
    //method to insert element
    Node* insert(Node *currentNode, int value) {
        if(currentNode == nullptr) {//if the node is empty
            return new Node(value);
        }
        if(currentNode->value < value) {//if value is bigger
            currentNode->right = insert(currentNode->right, value);
        }
        else {//if value is smaller
            currentNode->left = insert(currentNode->left, value);
        }
        return currentNode;
    }
    //method to remove element by value
    Node* remove(Node* currentNode, int value) {
        if(currentNode == nullptr) {//if the node is empty
            return nullptr;
        }
        if(currentNode->value < value) {//if value is bigger
            currentNode->right = remove(currentNode->right, value);
        }
        else if(currentNode->value > value) {//if value is smaller
            currentNode->left = remove(currentNode->left, value);
        }
        else {//found value
            if(currentNode->right == nullptr) {//if there is only left child
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            if(currentNode->left == nullptr) {//if there is only right child
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            //If there is two children,
            // find the smallest node in the right subtree
            // and replace it to the current node
            Node* minInRightSubtree = findMin(currentNode->right);
            currentNode->value = minInRightSubtree->value;
            currentNode->right = remove(currentNode->right, currentNode->value);
        }
        return currentNode;
    }
    //method to print tree by level
    void printLevelByLevel (Node* rootNode) {
        if(!rootNode) {
            return;
        }
        std::queue<Node*> queue;
        //push the root node
        queue.push(rootNode);
        while(true){
            //take the first element in the queue
            auto current = queue.front();
            queue.pop();
            std::cout << current->value << ' ';
            //push the left and right elements
            //in the next level by order
            if(current->left != nullptr){
                queue.push(current->left);
            }
            if(current->right != nullptr){
                queue.push(current->right);
            }
            //if queue is empty break
            if(queue.empty()) {
                break;
            }
        }
    }
    //method to find the smallest element in tree
    Node* findMin(Node *rootNode) {
        if(rootNode->left != nullptr) {
            return findMin(rootNode->left);
        }
        return rootNode;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }
    //method to insert element
    void insert(int value) {
        if(root == nullptr) {
            root = new Node(value);
        }
        else {
            insert(root, value);
        }
    }
    //method to remove element by value
    void remove(int value) {
        root = remove(root, value);
    }
    //method to print tree by level
    void printLevelByLevel() {
        printLevelByLevel(root);
    }
};

int main() {
    int numbersSize = 0;
    int removePlace = 0;
    std::cin >> numbersSize >> removePlace;

    BinarySearchTree tree;
    std::vector<int> sortNum;

    for (int i = 0; i < numbersSize; ++i) {
        int temp = 0;
        std::cin >> temp;
        sortNum.push_back(temp);
        tree.insert(temp);
    }
    //sort the elements in the vector
    //end remove element with wanted value
    sort(sortNum.begin(), sortNum.end(),
         [](int right, int left) {
             return right > left;
         }
    );
    tree.remove(sortNum[removePlace - 1]);
    //print the tree by level
    tree.printLevelByLevel();
}