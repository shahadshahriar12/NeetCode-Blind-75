#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool hasDuplicate(vector<int> &nums)
	{
		unordered_set<int> s;

		for (int i = 0; i < nums.size(); i++)
		{
			if (s.count(nums[i]))
			{
				return true;
			}
			else
			{
				s.insert(nums[i]);
			}
		}
		return false;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = {1, 2, 3, 3};
	bool ans = sol.hasDuplicate(nums);
	cout << ans << endl;
	return 0;
}

/*
Algorithm Used
The solution implements the Hash Set approach for detecting duplicates. Here's how it works:

Initialize: Create an unordered set (unordered_set<int> s) to store encountered numbers
Iterate: For each element in the array:
Check if the current number already exists in the set using count()
If the number exists (count() returns 1): A duplicate is found, return true immediately
If the number doesn't exist (count() returns 0): Insert the number into the set
Return: If the loop completes without finding duplicates, return false

Time Complexity Analysis
Time Complexity: O(n) average case, O(n²) worst case

The algorithm iterates through the array once: O(n)
For each element, it performs:
Hash set lookup using count(): O(1) average case, O(n) worst case
Hash set insertion: O(1) average case, O(n) worst case
Average case: O(n) × O(1) = O(n)
Worst case: O(n) × O(n) = O(n²) (when many hash collisions occur)

Space Complexity Analysis
Space Complexity: O(n)

In the worst case (no duplicates), the hash set stores all n unique elements
Each element is stored once in the set
Total auxiliary space: O(n)
*/