// n log n
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> resultVector;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    resultVector.push_back(i);
                    resultVector.push_back(j);

                    return resultVector;
                }
            }
        }

        return resultVector;
    }
};

// n
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // check if the complement already exists
            if (seen.find(complement) != seen.end()) {
                return { seen[complement], i };
            }

            // otherwise, store this number and its index
            seen[nums[i]] = i;
        }

        return {}; // no solution found (shouldn’t happen per problem statement)
    }
};
