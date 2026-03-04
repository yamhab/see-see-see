#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long card_count;
    cin >> card_count;

    vector<long long> cards(card_count);
    for (long long &card : cards)
        cin >> card;

    return 0;
}
