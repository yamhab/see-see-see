#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long position, target, giant, placement;
    cin >> position >> target >> giant >> placement;
    target = abs(target - position);
    position = 0;

    long long hops = target / giant;
    position += hops * giant;
    if (placement == 1 && abs(target - (position + giant)) < abs(target - position)) {
        ++hops;
        position += giant;
    } else if (placement == 2 && abs(target - (position + giant)) == abs(target - position)) {
        ++hops;
        position += giant;
    }
    cout << hops + abs(target - position) << '\n';

    return 0;
}
