#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
		unordered_map<string, vector<string>> anagramGroups;

		for(string s : strs)
		{
			vector<int> frequency(26, 0);
			for(char c: s)
			{
				frequency[c - 'a']++;
			}

			string key = "";
			for (int count : frequency) {
                key += to_string(count) + "#";
            }

			anagramGroups[key].push_back(s);
		}

		for(auto it = anagramGroups.begin(); it != anagramGroups.end(); it++)
		{
			solution.push_back(it->second);
		}

		return solution;
    }
};

int main()
{
	Solution sol;
	vector<string> strs = {"act","pots","tops","cat","stop","hat"};
	vector<vector<string>> ans = sol.groupAnagrams(strs);
	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout<<ans[i][j]<<"	";
		}
		cout << endl;
	}
	return 0;
}

/*
Algorithm Used
Steps:
Use a Hash Map:
Use a unordered_map<string, vector<string>> to group strings.
The key is a frequency count of characters represented as a string (e.g., "2#1#1#0#...#" for "aabc").

Group Strings:
For each string, calculate its frequency count and use it as the key.
Add the string to the corresponding group in the hash map.

Extract Results:
Convert the hash map values into the result vector.

Time Complexity
Frequency Count:
For each string, calculating the frequency count takes O(n), where n is the length of the string.
For m strings, this step takes O(m * n).
Hash Map Operations:
Insertion into the hash map is O(1) on average.

Total Time Complexity: O(m * n).

Space Complexity
Hash Map:
The hash map stores m keys (one for each unique group) and their corresponding vectors of strings.
The space required for the keys and values is proportional to the input size.
Frequency Array:
The frequency array is of fixed size (26), so it uses O(1) space.

Total Space Complexity: O(m).

*/
