#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int red, green, blue;
    cin >> red >> green >> blue;

    cout << 3 * red + 4 * green + 5 * blue;

    return 0;
}
