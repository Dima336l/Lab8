#include <iostream>

using namespace std;

class customerCounter {
  int maximumCustomers, customerCount;
public:
    customerCounter(int max);
  void add(int);
  void substract(int);
  void setMaximumCustomers(int);
  int getCustomerCount();
  int getMaximumCustomers();
};

customerCounter::customerCounter (int max) {
    maximumCustomers = max;
    customerCount = 0;
}

void customerCounter::setMaximumCustomers(int max) {
    maximumCustomers = max;
}

int customerCounter::getCustomerCount() {
    return customerCount;
}

int customerCounter::getMaximumCustomers() {
    return maximumCustomers;
}

    
void customerCounter::add (int numOfCustomers) {
    if (customerCount + numOfCustomers <= maximumCustomers) {
    customerCount += numOfCustomers;
    } else {
        cout << "The number your provided exceeds the maximum number of customers allowed" << endl;
        
    }
}

void customerCounter::substract (int numOfCustomers) {
    if ( customerCount - numOfCustomers >= 0) {
    customerCount -= numOfCustomers;
    } else {
        cout << "You want more customers than we have removed" << endl;
        
    }
}


int main () {
    customerCounter counter = (20);
    counter.add(5);
    cout << "After insertion there are: " << counter.getCustomerCount() << " customers" << endl;
    counter.add(10);
    cout << "After insertion there are: " << counter.getCustomerCount() << " customers" << endl;
    counter.substract(10);
    cout << "After substraction there are: " << counter.getCustomerCount() << " customers" << endl;
    counter.substract(2);
    cout << "After substraction there are: " << counter.getCustomerCount() << " customers" << endl;
    counter.add(20);
    counter.substract(5);
}
