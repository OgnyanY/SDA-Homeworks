#include <iostream>
#include <queue>

struct Student {
    int row = 0;
    int column = 0;

    Student(int row = 0, int column = 0) {
        this->row = row;
        this->column = column;
    }
};

void infection(int **cinema, std::queue<Student> &infected, int row, int rowSize, int column, int columnSize, int &counter) {
    if (column < 0 || row < 0 || column > columnSize - 1 || row > rowSize - 1) {
        return;
    } else {
        if (cinema[row][column] == 0) {
            ++cinema[row][column];
            Student ill(row, column);
            infected.push(ill);
            ++counter;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rowSize = 0, columnSize = 0, filmDuration = 0, ill = 0;
    std::cin >> rowSize >> columnSize;
    std::cin >> filmDuration >> ill;

    int **cinema = new int *[rowSize];
    for (int i = 0; i < rowSize; ++i) {
        cinema[i] = new int[columnSize]{0};
    }

    int counter = 0;
    std::queue<Student> infected;

    for (int i = 0; i < ill; ++i) {
        int row = 0;
        int column = 0;
        std::cin >> row >> column;
        --row;
        --column;
        if (column < 0 || row < 0 || column > columnSize - 1 || row > rowSize - 1) {
            continue;
        }
        if (cinema[row][column] == 0) {
            ++cinema[row][column];
            Student student(row, column);
            infected.push(student);
            ++counter;
        }
    }

    for (int i = 0; i < filmDuration; ++i) {
        size_t nowInfected = infected.size();
        for (size_t j = 0; j < nowInfected; ++j) {
            Student student = infected.front();
            infection(cinema, infected, student.row, rowSize, student.column - 1, columnSize, counter);
            infection(cinema, infected, student.row, rowSize, student.column + 1, columnSize, counter);
            infection(cinema, infected, student.row - 1, rowSize, student.column, columnSize, counter);
            infection(cinema, infected, student.row + 1, rowSize, student.column, columnSize, counter);
            infected.pop();
        }
    }

    for (int i = 0; i < rowSize; ++i) {
        delete[]cinema[i];
    }
    delete[]cinema;

    std::cout << (rowSize * columnSize) - counter;
}
