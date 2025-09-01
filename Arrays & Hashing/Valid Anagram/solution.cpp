#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

		if(s.size() != t.size()) return false;

        vector<int> frequency(26, 0);

		for(int i = 0; i < s.size(); i++)
		{
			frequency[s[i] - 'a']++;
			frequency[t[i] - 'a']--;
		}

		for(int i = 0; i < frequency.size(); i++)
		{
			if(frequency[i] != 0) return false;
		}

		return true;
    }
};

int main()
{
	Solution sol;
	bool ans = sol.isAnagram("racecar", "carrace");
	cout << ans << endl;
	return 0;
}

/*
Algorithm Used
Check Lengths:
If the lengths of s and t are not equal, return false immediately. This ensures that strings of different lengths cannot be anagrams.
Frequency Count:
Use a vector<int> of size 26 to count the frequency of each character in s and t.
For each character in s, increment its corresponding frequency.
For each character in t, decrement its corresponding frequency.
Validate Frequencies:
After processing both strings, check if all values in the frequency vector are 0. If any value is non-zero, it means the strings are not anagrams.

Time Complexity
Frequency Count: The loop iterates through the strings once, so this step takes O(n), where n is the length of the strings.
Validation: Checking the frequency vector takes O(26), which is constant time since the vector size is fixed at 26.
Total Time Complexity: O(n).

Space Complexity
The frequency vector uses O(1) space because its size is fixed at 26 (for lowercase English letters).
No additional data structures are used.
Total Space Complexity: O(1).
*/