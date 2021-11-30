#include <bits/stdc++.h>
#include <queue>
#include <vector>

//struct for task
struct Task {
    long long start = 0;//start time
    long long time = 0;//duration time
    long long index = 0;

    Task(long long start = 0, long long time = 0, long long index = 0) {
        this->start = start;
        this->time = time;
        this->index = index;
    }
};

//compare function for start time
auto sCmp = [](Task &a, Task &b) {
    return a.start > b.start;
};

//compare function for duration time
auto tCmp = [](Task &a, Task &b) {
    if (a.time > b.time) {
        return true;
    } else if (a.time == b.time) {
        if (a.index > b.index) {
            return true;
        } else {
            return false;
        }
    }
    return false;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);

    long long tasksSize = 0;
    std::cin >> tasksSize;

    std::priority_queue<Task, std::vector<Task>, decltype(sCmp)> startSort(sCmp);
    std::priority_queue<Task, std::vector<Task>, decltype(tCmp)> timeSort(tCmp);

    for (long long i = 0; i < tasksSize; ++i) {
        long long start = 0, time = 0;
        std::cin >> start >> time;
        Task task(start, time, i);
        startSort.push(task);
    }

    //print the index on first finished task
    std::cout << startSort.top().index << ' ';
    //time passed at all
    long long currentTime = startSort.top().start + startSort.top().time;
    startSort.pop();

    while (true) {
        while (true) {
            //if there is task to finish
            if (!startSort.empty() && startSort.top().start <= currentTime) {
                timeSort.push(startSort.top());
                startSort.pop();
            }
                //if there isn`t task to finish yet, get the next possible task to finish
            else if (!startSort.empty() && timeSort.empty() && startSort.top().start > currentTime) {
                timeSort.push(startSort.top());
                currentTime = startSort.top().start;
                startSort.pop();
            } else {
                break;
            }
        }

        //check tasks until there is new possible task to finish
        while ((startSort.empty() || currentTime < startSort.top().start) && (!timeSort.empty())) {
            std::cout << timeSort.top().index << ' ';
            currentTime += timeSort.top().time;
            timeSort.pop();
        }

        //if there is no more tasks
        if (startSort.empty() && timeSort.empty()) {
            break;
        } else {
            continue;
        }
    }
    return 0;
}
