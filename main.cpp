#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(begin(digits), 1);
        return digits;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = solution.plusOne(digits1);
    cout << "Input: digits = [1,2,3]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // Example 2
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = solution.plusOne(digits2);
    cout << "Input: digits = [4,3,2,1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i];
        if (i < result2.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // Example 3
    vector<int> digits3 = {9};
    vector<int> result3 = solution.plusOne(digits3);
    cout << "Input: digits = [9]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); ++i) {
        cout << result3[i];
        if (i < result3.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
