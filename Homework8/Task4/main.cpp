#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

//struct for operator
struct Operator {
    int time = 0;//time after which the operator will be free
    int calls = 0;//how many calls are received
    int index = 0;//index for operator

    Operator(int index = 0, int time = 0, int calls = 0) {
        this->index = index;
        this->time = time;
        this->calls = calls;
    }

    friend bool operator<(Operator const &lhs, Operator const &rhs) {
        if (lhs.calls > rhs.calls) {
            return true;
        } else if (lhs.calls == rhs.calls) {
            return lhs.index < rhs.index;
        }
        return false;
    }
};

int main() {
    int clientsSize = 0, operatorsSize = 0;
    std::cin >> clientsSize >> operatorsSize;

    //insert operators
    std::vector<Operator> operators(operatorsSize);
    for (int i = 0; i < operatorsSize; ++i) {
        operators[i].index = i;
    }

    //receive calls from clients
    for (int i = 0; i < clientsSize; ++i) {
        int startCall = 0, endCall = 0;
        std::cin >> startCall >> endCall;

        //if the operator on the wanted position is free
        //he receives the call
        if (operators[(i % operatorsSize)].time <= startCall) {
            operators[(i % operatorsSize)].time = startCall + endCall;
            ++operators[(i % operatorsSize)].calls;
            continue;
        } else {
            int next = i + 1;
            //if the wanted operator isn`t free,
            //look for next free operator to receives the call
            while ((next % operatorsSize) != (i % operatorsSize)) {
                if (operators[(next % operatorsSize)].time <= startCall) {
                    operators[(next % operatorsSize)].time = startCall + endCall;
                    ++operators[(next % operatorsSize)].calls;
                    break;
                }
                ++next;
            }
        }
    }

    std::make_heap(operators.begin(), operators.end());
    std::sort_heap(operators.begin(), operators.end());
    int max = operators[0].calls;
    //print the index of the operators who received the most calls
    for (int i = 0; i < operatorsSize; ++i) {
        if (operators[i].calls == max) {
            std::cout << operators[i].index << ' ';
        } else {
            break;
        }
    }
    return 0;
}
