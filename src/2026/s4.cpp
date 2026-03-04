#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long cart_count, gems;
    cin >> cart_count >> gems;

    vector<long long> carts(cart_count);
    for (long long &cart : carts)
        cin >> cart;

    long long max_capacity = 0;
    stack<long long> side_track;

    long long cheapest = *min_element(carts.begin(), carts.end());
    long long position = *find(carts.begin(), carts.end(), cheapest);

    // while (!carts.empty()) {
    //     long long next = carts.back();
    //     carts.pop_back();

    // }

    cout << max_capacity << '\n';

    return 0;
}
