#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int codes;
    cin >> codes;
    vector<string> new_codes;
    for (int i = 0; i < codes; ++i) {
        new_codes.push_back("");
        string original_code;
        cin >> original_code;

        bool negative = false;
        int n = 0;
        int sum = 0;
        for (char c : original_code) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
                continue;
            }

            if (negative)
                n *= -1;
            sum += n;
            n = 0;
            negative = false;

            if (isupper(c))
                new_codes[i].append({c});
            else if (c == '-')
                negative = true;
        }
        if (negative)
            n *= -1;
        sum += n;

        new_codes[i].append(to_string(sum));
    }

    for (string new_code : new_codes)
        cout << new_code << endl;
    return 0;
}
