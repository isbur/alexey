#pragma once

#include <vector>

int split(string s, vector<string> &answer) {
    istringstream iss(s);
    vector<string> polynomial_string(
            (
                istream_iterator<string>(iss)
            ),
            istream_iterator<string>()
        );
    answer = polynomial_string;
    return 0;
}