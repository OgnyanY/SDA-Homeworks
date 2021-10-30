#include <iostream>
#include <string>
int Homework (const std::string& str, const int maxL, const char symbol){
    int counter = 0;
    int strSize = (int)str.size();

    //here check how many of the symbol is in one word
    for(int i = 0;i < strSize;++i){
        if(str[i] == symbol){
            ++counter;
        }
    }
    //if there is none, return 0
    if(counter == 0){
        return counter;
    }
    //here check how whole words Mimi has to write and how symbols of the left word
    int wholeWords = maxL / strSize;
    int remainWord = maxL % strSize;

    //here count the symbol in the whole words
    counter = counter * wholeWords;

    //here check if there is left some symbol to count
    for(int i = 0; i < remainWord;++i){
        if(str[i] == symbol){
            ++counter;
        }
    }
    return counter;
}

int main() {
    std::string word;
    int number;
    char symbol;
    std:: cin >> word >> number >> symbol;
    std::cout << Homework(word, number, symbol);
    return 0;
}
