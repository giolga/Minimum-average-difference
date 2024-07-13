#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    public:
        int minimumAverageDifference(vector<int>& nums) {
            int minIdx = 0;
            int minVal = INT_MAX;
            long long totalSum = 0;
            long long prefixSum = 0;
            int n = nums.size();    

            for(int i = 0; i < nums.size(); i++) {
                totalSum += nums[i];
            }

            for(int i = 0; i < n; i++) {
                prefixSum += nums[i];
                int leftAvg = prefixSum / (i + 1);
                int rightAvg = 0;

                if(i < n - 1) {
                    rightAvg = (totalSum - prefixSum) / (n - i - 1);
                }

                int diff = abs(rightAvg - leftAvg);
                if(diff < minVal) {
                    minVal = diff;
                    minIdx = i;
                }
            }

            return minIdx;
        }
};