#include <iostream>
#include <stack>
#include <queue>
#include <vector>

//fight function
int Fight(std::stack<int>& positive, int fighter) {
    while(!positive.empty()){
        int positiveFront = positive.top();
        int negativeFighter = abs(fighter);
        if(positiveFront > negativeFighter){
            return 1;
        }
        else if(positiveFront < negativeFighter){
            positive.pop();
        }
        else {
            positive.pop();
            return 0;
        }
    }
    return 2;
}

int main() {
    int fighterSize = 0;
    std::cin >> fighterSize;
    std::queue<int> fighters;
    int fighter = 0;

    for (int i = 0; i < fighterSize; ++i) {
        std::cin >> fighter;
        fighters.push(fighter);
    }

    std::stack<int> positive;//stack of positive numbers
    std::vector<int> lastPositive;

    //flag to see if there is negative number
    bool negativeFighter = false;
    //flag to see if there is elements in the stack of positive numbers
    bool positiveFighter = false;

    int passed = 0;

    while(!fighters.empty()) {
        fighter = fighters.front();

        //if in the begging of queue is negative
        //and there are no elements in the stack
        if(positive.empty() && fighter < 0) {
            std::cout << fighter << " ";
            fighters.pop();
            continue;
        }

        if(fighter > 0) {//add positive number
            positiveFighter = true;

            positive.push(fighter);
            fighters.pop();
        }
        //found negative number
        else if(fighter < 0 && positiveFighter) {
            negativeFighter = true;
        }
        //fight
        if(negativeFighter){
            int fight = Fight(positive, fighter);
            if(fight == 1) {//there are elements in the stack
                fighters.pop();
                negativeFighter = false;
            }
            else if(fight == 2) {//there are no elements in the stack
                positiveFighter = false;
                negativeFighter = false;
            }
            else {//par
                fighters.pop();
                if(positive.empty()){
                    positiveFighter = false;
                }
                negativeFighter = false;
            }
        }
        //if there are last positive numbers
        if(fighters.empty() && !positive.empty()) {

            while(!positive.empty()) {
                lastPositive.push_back(positive.top());
                positive.pop();
            }
            //reverse the numbers in the correct order
            for (int i = lastPositive.size() - 1; i >= 0; --i) {
                std::cout << lastPositive[i] << " ";
            }
        }
    }
    std::cout << '\n';
    return 0;
}
