#include <iostream>
#include <vector>
#include <algorithm>

void path(const std::vector<std::vector<char>> &maze, std::vector<std::vector<bool>> visited,
          int row, int &rowSize, int col, int &colSize,
          int &minuses, int passed, int &answer) {


    if (col < 0 || row < 0 || col > colSize - 1 || row > rowSize - 1) {
        return;
    }
    if (visited[row][col]) {
        return;
    }
    if (maze[row][col] == 'x') {
        return;
    }
    if (maze[row][col] == 'e' && passed == minuses) {
        ++answer;
        return;
    }
    visited[row][col] = true;
    ++passed;

    path(maze, visited, row + 1, rowSize, col, colSize, minuses, passed, answer);
    path(maze, visited, row - 1, rowSize, col, colSize, minuses, passed, answer);
    path(maze, visited, row, rowSize, col + 1, colSize, minuses, passed, answer);
    path(maze, visited, row, rowSize, col - 1, colSize, minuses, passed, answer);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rowSize = 0, colSize = 0;
    std::cin >> rowSize >> colSize;

    std::vector<std::vector<char>> maze(rowSize);
    std::vector<std::vector<bool>> visited(rowSize);
    int minuses = 0;
    int xStart = 0;
    int yStart = 0;
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            char x;
            std::cin >> x;
            if (x == 's') {
                xStart = i;
                yStart = j;
            }
            if (x == '-') {
                ++minuses;
            }

            maze[i].push_back(x);
            visited[i].push_back(false);
        }
    }
    int answer = 0;
    path(maze,visited,xStart,rowSize,yStart,colSize,minuses,-1,answer);
    std::cout << answer;
}
