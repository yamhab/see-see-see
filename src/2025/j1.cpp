#include <iostream>

using namespace std;

int main() {
    int pos, cars, capacity;
    cin >> pos >> cars >> capacity;
    cout << (pos <= cars * capacity ? "yes" : "no") << endl;
    return 0;
}
