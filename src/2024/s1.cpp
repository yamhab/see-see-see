#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long people;
    cin >> people;

    vector<long long> hats(people);
    for (long long &hat : hats)
        cin >> hat;

    long long sum = 0;
    for (long long i = 0; i < people; ++i)
        if (hats[i] == hats[(i + people / 2) % people])
            ++sum;
    cout << sum << '\n';

    return 0;
}
