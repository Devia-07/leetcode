#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string y = to_string(x);
        int n = y.size();
        for (int i = 0; i < n / 2; i++) {
            if (y[i] != y[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};