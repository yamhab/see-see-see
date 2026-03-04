#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dusa;
    cin >> dusa;

    int yobi;
    cin >> yobi;
    while (yobi < dusa) {
        dusa += yobi;
        cin >> yobi;
    }

    cout << dusa << '\n';

    return 0;
}
