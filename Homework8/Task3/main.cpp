#include <bits/stdc++.h>
#include <queue>
#include <vector>

//struct for student
struct Student {
    long finish = 0;//finish time
    long code = 0;//code lines

    Student(long finish = 0, long code = 0) {
        this->finish = finish;
        this->code = code;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int studentsSize = 0;
    std::cin >> studentsSize;

    std::pair<long, long> answer(0,0);//variable to find the answer

    //compare function for finish time
    auto fCmp = [](Student &a, Student &b) {
        return a.finish > b.finish;
    };
    //compare function for code lines
    auto cCmp = [](Student &a, Student &b) {
        return a.code > b.code;
    };

    std::priority_queue<Student, std::vector<Student>, decltype(fCmp)> finishSorted(fCmp);
    std::priority_queue<Student, std::vector<Student>, decltype(cCmp)> codeSorted(cCmp);

    for (int i = 0; i < studentsSize; ++i) {
        long finish = 0, code = 0;
        std::cin >> finish >> code;
        Student student(finish, code);
        finishSorted.push(student);
    }

    //add data for first student finished the exam
    answer.first += finishSorted.top().code;
    ++answer.second;
    //time passed at all
    long currentTime = finishSorted.top().finish + finishSorted.top().code;
    finishSorted.pop();

    while (true) {
        while (true) {
            //if there is student finished the exam
            if (!finishSorted.empty() && finishSorted.top().finish <= currentTime) {
                codeSorted.push(finishSorted.top());//sort student by code
                finishSorted.pop();
            }
            //if there isn`t student finished the exam
            else if (!finishSorted.empty() && codeSorted.empty() && finishSorted.top().finish > currentTime) {
                codeSorted.push(finishSorted.top());
                currentTime = finishSorted.top().finish;
                finishSorted.pop();
            }else{
                break;
            }
        }

        //check tests until there is no other student finished the exam
        while((finishSorted.empty() || currentTime < finishSorted.top().finish) && (!codeSorted.empty())){
            answer.first += currentTime - codeSorted.top().finish + codeSorted.top().code;
            ++answer.second;
            currentTime += codeSorted.top().code;
            codeSorted.pop();
        }

        //there is no more students
        if(finishSorted.empty() && codeSorted.empty()){
            break;
        }else{
            continue;
        }
    }
    std::cout << answer.first / answer.second;
    return 0;
}
