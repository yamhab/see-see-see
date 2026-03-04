#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input, output;
    cin >> input >> output;
    int length = input.length();

    char silly_input = '-';
    char silly_output = '-';
    char quiet_key = '-';
    int j = 0;
    for (int i = 0; i < length; ++i) {
        if (silly_input != '-' && silly_output != '-' && quiet_key != '-')
            break;

        if (input[i] == output[j]) {
            ++j;
            continue;
        }

        int k = 1;
        while (input[i + k] == input[i])
            ++k;

        if (input[i + k] == output[j]) {
            quiet_key = input[i];
        } else {
            silly_input = input[i];
            silly_output = output[j++];
        }
    }

    cout << silly_input << ' ' << silly_output << '\n' << quiet_key << '\n';

    return 0;
}
