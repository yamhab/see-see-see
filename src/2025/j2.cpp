#include <iostream>

using namespace std;

int main() {
    int donuts, events;
    cin >> donuts >> events;
    for (int i = 0; i < events; ++i) {
        char symbol;
        int quantity;
        cin >> symbol >> quantity;
        switch (symbol) {
            case '+':
                donuts += quantity;
                break;
            case '-':
                donuts -= quantity;
                break;
        }
    }
    cout << donuts << endl;
    return 0;
}
