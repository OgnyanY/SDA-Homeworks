#include <iostream>
#include <vector>

class Person {
private:
    unsigned int presents;
    std::vector<Person*> employees;
public:
    Person(int presents = 0) {
        this->presents = presents;
    }

    //add employee to the employer
    void addEmployee(Person* newEmployee) {
        this->employees.push_back(newEmployee);
    }

    //method that get how presents the employer has to buy
    unsigned int getPresents() {
        //buy presents for the direct employees
        this->presents = employees.size();
        if(!employees.empty()) {
            //buy presents for the indirect employees
            for (auto & employee : employees) {
                presents += employee->getPresents();
            }
        }
        return this->presents;
    }
};

int main() {
    int employees  = 0;
    std::cin >> employees;

    std::vector<Person*> employers;
    //make space for employers
    for (int i = 0; i < employees; ++i) {
        auto* person = new Person();
        employers.push_back(person);
    }
    //attach employees to the employers
    for (int i = 0; i < employees - 1; ++i) {
        int parent = 0;
        int child = 0;
        std::cin >> parent >> child;
        employers[parent]->addEmployee(employers[child]);
    }
    //print presents
    for (int i = 0; i < employees; ++i) {
        std::cout << employers[i]->getPresents() << ' ';
    }

}