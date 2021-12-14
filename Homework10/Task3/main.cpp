#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

void topologicalOrder(std::set<char> &visited, std::stack<char> &answer,
                      std::unordered_map<char, std::set<char>> &symbols, char letter) {
    if(visited.count(letter)){
        return;
    }
    for (auto it = symbols[letter].begin(); it != symbols[letter].end(); ++it) {
        char symbol = *it;
        if(visited.count(*it) == 0){
            topologicalOrder(visited, answer, symbols, *it);
            visited.insert(*it);
        }
    }
    answer.push(letter);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int wordsSize = 0;
    std::cin >> wordsSize;

    std::unordered_map<char, std::set<char>> symbols;

    std::vector<std::string> dictionary;
    for (int i = 0; i < wordsSize; ++i) {
        std::string word;
        std::cin >> word;
        dictionary.push_back(word);
    }
    for (auto &i: dictionary) {
        for (char &j: i) {
            symbols[j] = std::set<char>();
        }
    }
    for (int i = 0; i < wordsSize - 1; ++i) {
        std::string first = dictionary[i], second = dictionary[i + 1];
        int j = 0;
        while (first[j] != '\0' && second[j] != '\0') {
            if (first[j] != second[j]) {
                symbols[first[j]].insert(second[j]);
                break;
            }
            ++j;
        }
    }

    std::set<char> visited;
    std::stack<char> answer;
    for (auto it = symbols.begin(); it != symbols.end(); ++it) {
        char symbol = it->first;
        topologicalOrder(visited, answer, symbols, symbol);
        if(visited.count(symbol) == 0){
            visited.insert(symbol);
        }
    }
    while(!answer.empty()){
        std:: cout << answer.top() << ' ';
        answer.pop();
    }
}
