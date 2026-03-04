#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int width_1, height_1, width_2, height_2;
    cin >> width_1 >> height_1 >> width_2 >> height_2;

    int left_right = 2 * (width_1 + width_2 + max(height_1, height_2));
    int top_bottom = 2 * (max(width_1, width_2) + height_1 + height_2);

    cout << min(left_right, top_bottom) << '\n';

    return 0;
}
