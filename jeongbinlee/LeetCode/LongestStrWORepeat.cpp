#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	Solution() {

	}

	int lengthOfLongestSubstring(string s) {
		int len = s.length(), tempLen = 0, maxLen = 0, offset = 0;
		vector<int> visitTable(256, -1);

		for (int idx = 0; idx < len; idx++) {
			if (visitTable[s[idx]] == -1) {
				visitTable[s[idx]] = idx;
				tempLen++;
			}
			else {
				if (visitTable[s[idx]] + 1 > offset) offset = visitTable[s[idx]] + 1;
				visitTable[s[idx]] = idx;
				tempLen = idx - offset + 1;
			}

			if (tempLen > maxLen) maxLen = tempLen;
		}

		return maxLen;
	}
};

int main() {
	Solution sol;
	string input;
	do {
		cout << "input : ";
		cin >> input;

		cout << "answer : ";
		cout << sol.lengthOfLongestSubstring(input) << endl;
	} while (input != "exit");
	
	return 0;
}