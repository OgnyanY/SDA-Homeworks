#include <iostream>
#include <set>

void find(std::set<int> &allSubMasks, int mask, int subMask) {
    if (subMask < 0) {//if there is no more sub masks
        return;
    }
    //find next possible sub mask
    int nextSubMask = subMask & mask;
    allSubMasks.insert(nextSubMask);
    //continue until there is no more sub masks
    find(allSubMasks, mask, nextSubMask - 1);
}

void findSubMasks(std::set<int> &allSubMasks, int mask) {
    allSubMasks.insert(mask);//insert the mask as sub mask
    int nextSubMask = mask - 1;//next eventually sub mask
    find(allSubMasks, mask, nextSubMask);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int masksSize = 0;
    std::cin >> masksSize;

    std::set<int> allSubMasks;
    //get masks
    for (int i = 0; i < masksSize; ++i) {
        int mask = 0;
        std::cin >> mask;
        findSubMasks(allSubMasks, mask);
    }
    //print the size of the sub masks
    std::cout << allSubMasks.size();
    return 0;
}
