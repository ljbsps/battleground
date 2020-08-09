#pragma once
#ifndef _ADDTWONUMBERS_H_
#define _ADDTWONUMBERS_H_

#include <stdio.h>
#include <vector>
using namespace std;

namespace LeetCode {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class AddTwoNumbers
	{
	public:
		AddTwoNumbers(ListNode* l1, ListNode* l2);
		~AddTwoNumbers();
		ListNode* GetValue();
		void Sum();

	private:
		ListNode* input1;
		ListNode* input2;
		ListNode* sum;
		ListNode* FindIndex(int idx);
	};
}

#endif