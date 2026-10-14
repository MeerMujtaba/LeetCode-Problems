#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Each digit is at most 9, so the maximum possible sum is 9 * num
        if (sum > 9LL * num) {
            return "";
        }

        int nines = sum / 9;
        int rem = sum % 9;

        // 1. Fill with as many '9's as possible
        string ans(nines, '9');

        // 2. Append the remainder digit if non-zero
        if (rem > 0) {
            ans.push_back('0' + rem);
        }

        // 3. Pad the rest with '0's to reach exactly `num` digits
        ans.append(num - ans.size(), '0');

        return ans;
    }
};
