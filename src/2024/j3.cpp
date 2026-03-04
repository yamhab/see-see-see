#include <array>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int participants;
    cin >> participants;

    array<int, 2> gold = {0, 0}, silver = {0, 0}, bronze = {0, 0};
    for (int i = 0; i < participants; ++i) {
        int score;
        cin >> score;

        if (score == gold[0]) {
            ++gold[1];
        } else if (score == silver[0]) {
            ++silver[1];
        } else if (score == bronze[0]) {
            ++bronze[1];
        } else if (score > gold[0]) {
            bronze = silver;
            silver = gold;
            gold = {score, 1};
        } else if (score > silver[0]) {
            bronze = silver;
            silver = {score, 1};
        } else if (score > bronze[0]) {
            bronze = {score, 1};
        }
    }

    cout << bronze[0] << ' ' << bronze[1] << '\n';

    return 0;
}
