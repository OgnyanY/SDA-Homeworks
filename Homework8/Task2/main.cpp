#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

struct Task {
    long start = 0;
    long time = 0;
    long index = 0;

    Task(long start = 0, long time = 0, long index = 0) {
        this->start = start;
        this->time = time;
        this->index = index;
    }
};

int main() {

    /*
     5
2 1
1 5
 3 3
2 4
7 1
*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    int tasksSize = 0;
    cin >> tasksSize;

    auto sCmp = [](Task &a, Task &b) {
        return a.start > b.start;
    };
    auto tCmp = [](Task &a, Task &b) {
        return a.time > b.time;
    };
    std::priority_queue<Task, std::vector<Task>, decltype(sCmp)> startSort(sCmp);
    std::priority_queue<Task, std::vector<Task>, decltype(tCmp)> timeSort(tCmp);

    for (int i = 0; i < tasksSize; ++i) {
        long start = 0, time = 0;
        cin >> start >> time;
        Task task(start, time, i);
        startSort.push(task);
    }
    cout << startSort.top().index << ' ';
    long time = startSort.top().start + startSort.top().time;
    startSort.pop();

    while (true) {
        while (true) {
            if (!startSort.empty() && startSort.top().start <= time) {
                timeSort.push(startSort.top());
                startSort.pop();
            }else if (!startSort.empty() && timeSort.empty() && startSort.top().start > time) {
                timeSort.push(startSort.top());
                time = startSort.top().start;
                startSort.pop();
            }else{
                break;
            }
        }

        while((startSort.empty() || time < startSort.top().start) && (!timeSort.empty())){
            cout << timeSort.top().index << ' ';
            time += timeSort.top().time;
            timeSort.pop();
        }

        if(startSort.empty() && timeSort.empty()){
            break;
        }else{
            continue;
        }
    }

    return 0;
}
