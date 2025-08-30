#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sumMap;
        vector<int> solution;

        for(int i = 0; i < nums.size(); i++)
        {
            auto query = sumMap.find(target - nums[i]);

            if(query == sumMap.end())
            {
                sumMap.insert({nums[i], i});
            }
            else
            {
                solution.push_back(query->second);
                solution.push_back(i);
                return solution;
            }
        }
    }
};

int main() {
	Solution sol;
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	vector<int> result = sol.twoSum(nums, target);
	
	cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
	return 0;
}

/* Algorithm Used
The solution implements the Hash Map (Hash Table) approach for the Two Sum problem. Here's how it works:

Initialize: Create a hash map (map<int, int> sumMap) to store numbers and their indices
Iterate: For each element in the array:
Calculate the complement: target - nums[i]
Check if the complement exists in the hash map
If complement is not found: Store the current number and its index in the hash map
If complement is found: Return the indices of the complement and current element
Return: The function returns the indices of the two numbers that add up to the target

Time Complexity Analysis
Time Complexity: O(n)

The algorithm makes a single pass through the array of n elements
For each element, it performs:
Hash map lookup: O(1) average case
Hash map insertion: O(1) average case
Total: O(n) × O(1) = O(n)

Space Complexity Analysis
Space Complexity: O(n)

In the worst case, the hash map stores all n elements before finding the solution
This happens when the target pair is the last element and one other element
The solution vector uses O(1) space (always stores exactly 2 elements)
Total auxiliary space: O(n) + O(1) = O(n)
*/