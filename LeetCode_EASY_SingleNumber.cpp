// Leet Code Problem 136. Single Number | This program runs a linear search to determine which element in the array is the single number if found. 
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        for (size_t i = 0; i < nums.size(); i++) {
            bool found = false;

            for (size_t j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return nums[i];
            }
        }

        return -1; 
    }
};

int main() {
    Solution sol;

   
    vector<int> nums1 = { 7, 7, 3 };
    cout << "Array 1: [7, 7, 3]" << endl;
    cout << "The Single Number Is: " << sol.singleNumber(nums1) << endl << endl;

  
    vector<int> nums2 = { 9, 9, 4, 4, 5 };
    cout << "Array 2: [9, 9, 4, 4, 5]" << endl;
    cout << "The Single Number Is: " << sol.singleNumber(nums2) << endl;

    return 0;
}