#pragma once
#ifndef _TWOSUM_H_
#define _TWOSUM_H_

#include <stdio.h>
#include <vector>
using namespace std;

namespace LeetCode {
	class TwoSum 
	{
	public:
		TwoSum(vector<int>& nums, int target);
		~TwoSum();
		vector<int> GetValue();
		void Sum();
	private:
		vector<int> input;
		vector<int> output;
		int target;
	};
}

#endif