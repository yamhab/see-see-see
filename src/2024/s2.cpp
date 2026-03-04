#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long count, length;
    cin >> count >> length;
    vector<string> sequences(count, string(length, 0));
    vector<array<long long, 26>> heavinesses(count);
    for (long long i = 0; i < count; ++i) {
        cin >> sequences[i];
        heavinesses[i].fill(0);
        for (char letter : sequences[i])
            ++heavinesses[i][letter - 'a'];
    }

    for (long long i = 0; i < count; ++i) {
        bool heavy_alternating = true;
        bool light_alternating = true;
        for (long long j = 0; j < length; ++j) {
            long long heaviness = heavinesses[i][sequences[i][j] - 'a'];
            if (heaviness < 2)
                heavy_alternating = false;
            else
                light_alternating = false;

            if (++j >= length)
                continue;

            heaviness = heavinesses[i][sequences[i][j] - 'a'];
            if (heaviness > 1)
                heavy_alternating = false;
            else
                light_alternating = false;
        }
        cout << (heavy_alternating || light_alternating ? "T\n" : "F\n");
    }

    return 0;
}
