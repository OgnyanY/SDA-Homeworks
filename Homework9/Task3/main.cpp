#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std:: vector<std::vector<int>> matrix (str1.size());
    int max = 0;
    int rows = 0, d = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
        for (size_t j = 0; j < str2.size(); ++j) {
            if (str1[i] == str2[j]) {
                if (i > 0 && j > 0) {
                    matrix[i].push_back(matrix[i - 1][j - 1] + 1);
                    if (max < matrix[i][j]) {
                        max = matrix[i][j];
                    }
                } else {
                    matrix[i].push_back(1);
                    if (max < matrix[i][j]) {
                        max = matrix[i][j];
                    }
                }
            } else {
                matrix[i].push_back(0);
            }
        }
        ++rows;
        if(rows > 2){
            matrix[d].erase(matrix[d].begin(),matrix[d].end());
            rows = 0;
            ++d;
        }
    }
    std::cout << max;

    return 0;
}
