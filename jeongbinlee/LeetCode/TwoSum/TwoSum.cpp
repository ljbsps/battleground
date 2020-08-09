#include <iostream>
#include <vector>
#include "TwoSum.h"
using namespace std;

namespace LeetCode {
	TwoSum::TwoSum(vector<int>& nums, int target)
	{
		input = nums;
		this->target = target;
		Sum();
	}

	TwoSum::~TwoSum()
	{
	}

	vector<int> TwoSum::GetValue() {
		return output;
	}

	void TwoSum::Sum() {
		for (int i = 0; i < input.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (i == j)continue;
				if (input[j] + input[i] == target)
					output = vector<int>{j, i};
			}
		}
	}
}