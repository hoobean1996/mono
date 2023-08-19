// leetcode 229
// Majority Element II
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int count1 = 0;
    int count2 = 0;

    int majority1 = 1e9 + 1;
    int majority2 = 1e9 + 1;

    for (int i = 0; i < nums.size(); i++) {
      if (majority1 != 1e9 + 1 && nums[i] == majority1)
        count1++;
      else if (majority2 != 1e9 + 1 && nums[i] == majority2)
        count2++;
      else if (count1 == 0) {
        majority1 = nums[i];
        count1++;
      } else if (count2 == 0) {
        majority2 = nums[i];
        count2++;
      } else {
        count1--;
        count2--;
      }
    }

    vector<int> ans;

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (majority1 != 1e9 + 1 && nums[i] == majority1)
        count1++;
      if (majority2 != 1e9 + 1 && nums[i] == majority2)
        count2++;
    }

    if (count1 > nums.size() / 3)
      ans.push_back(majority1);
    if (count2 > nums.size() / 3)
      ans.push_back(majority2);

    return ans;
  }
};