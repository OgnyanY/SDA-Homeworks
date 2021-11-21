#include <iostream>
#include <set>

static const int MAX_INT = 2147483647;

void xorSet(std::set<int> &storage, int &minXOR, int number) {
    int lowerXOR = MAX_INT;//make lowerXOR the biggest possible
    int upperXOR = MAX_INT;//make upperXOR the biggest possible

    //if number is placed first it doesn't have lower number
    if (number != *(storage.begin())) {
        lowerXOR = number ^ *(--storage.find(number));
    }
    //if number is placed last it doesn't have upper number
    if (number != *(--storage.end())) {
        upperXOR = number ^ *(++storage.find(number));
    }

    //compare current minXOR, lowerXOR and upperXOR
    //print the smallest
    if (lowerXOR < minXOR && lowerXOR < upperXOR) {
        minXOR = lowerXOR;
        printf("%d \n",minXOR);
    } else if (upperXOR < minXOR && upperXOR < lowerXOR) {
        minXOR = upperXOR;
        printf("%d \n",minXOR);
    } else {
        printf("%d \n",minXOR);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int requests = 0;
    std::cin >> requests;

    std::set<int> storage;
    storage.insert(0);

    int minXOR = MAX_INT;//make minXOR the biggest possible
    size_t storageSize = 1;//current size of the storage
    for (int i = 0; i < requests; ++i) {
        int number = 0;
        std::cin >> number;
        storage.insert(number);

        //if number don`t exist in the storage,
        //storageSize wil be smaller than the actual size of the storage
        //and then check for new minXOR
        if (storageSize < storage.size()) {
            xorSet(storage, minXOR, number);
            ++storageSize;
        } else {// if number exist in the storage, print the current minXOR
            printf("%d \n",minXOR);
        }
    }
    return 0;
}
