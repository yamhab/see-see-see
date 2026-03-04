#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int days;
    cin >> days;

    bool none = true;
    bool all = true;

    int longest_streak = 0, first_chain = 0, second_chain = 0;
    bool used_incorrect = false;
    for (int i = 0; i < days; ++i) {
        char weather;
        cin >> weather;
        bool sunshine = (weather == 'S') ? true : false;

        if (sunshine)
            none = false;
        if (!sunshine)
            all = false;

        if (sunshine && !used_incorrect) {
            ++first_chain;
        } else if (!sunshine && !used_incorrect) {
            used_incorrect = true;
        } else if (sunshine && used_incorrect) {
            ++second_chain;
        } else if (!sunshine && used_incorrect) {
            first_chain = second_chain;
            second_chain = 0;
        }

        longest_streak = max(longest_streak, first_chain + second_chain + (used_incorrect ? 1 : 0));
    }

    if (all)
        cout << days << endl;
    else if (none)
        cout << "0" << endl;
    else
        cout << longest_streak << '\n';
    return 0;
}
