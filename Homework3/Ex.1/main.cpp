#include <iostream>

long Cube (long num) {
    return num * num * num;
}

int main() {
   long long points = 0;
   std::cin >> points;

   int presents = 0;
   long num = 1;
    while (points != 0){
        if (Cube(num) < points) {
            ++num;
            continue;
        }
        else if (Cube(num) > points) {
            points -= Cube(num - 1);
            ++presents;
            num = 1;
        }
        else {
            points -= Cube(num);
            ++presents;
            num = 1;
        }
    }
    std::cout << presents;
}
