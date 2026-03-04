#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern;
    long long i;
    cin >> pattern >> i;

    vector<tuple<char, long long>> cipher;
    long long length = 0;
    for (long long j = 0; j < (int)pattern.length(); ++j) {
        char letter = pattern[j];

        long long count = 0;
        do {
            count *= 10;
            count += pattern[++j] - '0';
        } while (isdigit(pattern[j + 1]));
        length += count;

        cipher.push_back({letter, count});
    }
    i %= length;

    long long pos = 0;
    for (tuple<char, long long> j : cipher) {
        if (i >= pos && i < (pos += get<1>(j))) {
            cout << get<0>(j) << '\n';
            break;
        }
    }

    return 0;
}
