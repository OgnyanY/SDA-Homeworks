#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

//topological order for symbols
void topologicalOrder(std::set<char> &visited, std::stack<char> &answer,
                      std::unordered_map<char, std::set<char>> &symbols, char symbol) {
    //if the symbols is visited return
    if(visited.count(symbol)){
        return;
    }
    //check if the symbol lead to other symbols
    for (auto it = symbols[symbol].begin(); it != symbols[symbol].end(); ++it) {
        //if the symbol is not visited chek it
        if(visited.count(*it) == 0){
            topologicalOrder(visited, answer, symbols, *it);
            visited.insert(*it);//make the symbol visited
        }
    }
    answer.push(symbol);//push the symbol to the stack for print
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int wordsSize = 0;//how many words are in the dictionary
    std::cin >> wordsSize;

    std::unordered_map<char, std::set<char>> symbols;//unique symbols

    std::vector<std::string> dictionary;
    for (int i = 0; i < wordsSize; ++i) {
        std::string word;
        std::cin >> word;
        dictionary.push_back(word);//push word in the dictionary
    }
    for (auto &i: dictionary) {//find unique symbols
        for (char &j: i) {
            symbols[j] = std::set<char>();
        }
    }

    for (int i = 0; i < wordsSize - 1; ++i) {//find the connections for every symbol
        std::string first = dictionary[i], second = dictionary[i + 1];
        int j = 0;
        while (first[j] != '\0' && second[j] != '\0') {
            //if the symbols are not equal,
            //the symbol in the first word has to lead to a symbol in the second word
            if (first[j] != second[j]) {
                symbols[first[j]].insert(second[j]);
                break;
            }
            ++j;
        }
    }

    std::set<char> visited;
    std::stack<char> answer;
    //sort the symbols
    for (auto it = symbols.begin(); it != symbols.end(); ++it) {
        char symbol = it->first;
        topologicalOrder(visited, answer, symbols, symbol);
        //if the symbol is not visited make it visited
        if(visited.count(symbol) == 0){
            visited.insert(symbol);
        }
    }
    // print the symbols
    while(!answer.empty()){
        std:: cout << answer.top() << ' ';
        answer.pop();
    }
}
