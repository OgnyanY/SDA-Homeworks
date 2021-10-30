#include <iostream>

//count cube of number
long Cube (long num) {
    return num * num * num;
}

int main() {
   long long points = 0;
   std::cin >> points;

   int presents = 0;
   long num = 1;
    while (points != 0){
        //this is when the value is not enough
        if (Cube(num) < points) {
            ++num;
            continue;
        }
        //when the value is bigger than points get the less value
        else if (Cube(num) > points) {
            points -= Cube(num - 1);
            ++presents;
            num = 1;
        }
        //when the value is the same points get the less value
        else {
            points -= Cube(num);
            ++presents;
            num = 1;
        }
    }
    std::cout << presents;
}
