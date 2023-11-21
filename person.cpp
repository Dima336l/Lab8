#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
    private: 
        vector<Person*> vecOfPersons;
    public:
        string name;
        Person(string str) {
            name = str;
        }
        
        void showFriends() {
            if (vecOfPersons.size() == 0) {
                cout << name << " has no friends :( " << endl;
            } else {
                cout << name << " has the following friends: ";
            for (size_t i = 0 ; i < vecOfPersons.size();i++) {
                cout << vecOfPersons[i]->name << " ";
            }
            cout << endl;
            }
            };
        
        
        void befriend(Person *pers) {
            vecOfPersons.push_back(pers);
        };
        
        void unfriend(Person *pers) {
        vecOfPersons.erase(remove_if(vecOfPersons.begin(), vecOfPersons.end(),
                                     [pers](const Person* p) { return p == pers; }),
                            vecOfPersons.end());
};
};

int main () {
Person *person1 = new Person("Dumitru");
Person *person2 = new Person("Ion");
Person *person3 = new Person("Paul");
Person *person4 = new Person("Stefan");
Person *person5 = new Person("Artur");

person1->showFriends();
person1->befriend(person2);
person1->befriend(person3);
person1->befriend(person4);
person1->befriend(person5);
person1->showFriends();
person1->unfriend(person2);
person1->unfriend(person3);
person1->unfriend(person4);
person1->showFriends();

delete(person1);
delete(person2);
delete(person3);
delete(person4);
delete(person5);


}
