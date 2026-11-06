// TITLE: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order. Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> result(m + n);

        int i, j;
        i = j = 0;

        while (i + j < m + n) {
            if (i >= m) {
                result.push_back(nums2[j]);
                j++;
                continue;
            }

            if (j >= n) {
                result.push_back(nums1[i]);
                i++;
                continue;
            }

            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        return result;
    }
};

// Quick helper to print std::vector
template <typename T>
void printVector(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 3, 5, 9, 11};
    int n = 5;
    vector<int> nums2 = {1, 2, 3, 400};
    int m = 4;
    vector<int> expected = {1, 2, 2, 3, 3, 5, 9, 11, 400};

    vector<int> result = sol.merge(nums1, n, nums2, m);
    cout << "Test 1 Output: ";
    printVector(result);
    assert(result == expected);
}
