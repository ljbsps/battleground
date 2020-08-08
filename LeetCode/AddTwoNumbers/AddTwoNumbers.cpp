#include <iostream>
#include <vector>
#include "AddTwoNumbers.h"
using namespace std;

namespace LeetCode {
	AddTwoNumbers::AddTwoNumbers(ListNode* l1, ListNode* l2)
	{
		this->input1 = l1;
		this->input2 = l2;
		sum = new ListNode();
	}

	AddTwoNumbers::~AddTwoNumbers() 
	{
	}

	ListNode* AddTwoNumbers::GetValue()
	{
		return sum;
	}

	void AddTwoNumbers::Sum()
	{
		ListNode ld1 = input1[0], ld2 = input2[0], temp;
		ListNode* addNode;
		int idx = 0, extra = 0;
		bool isLast = false;

		if (ld1.next == nullptr && ld2.next == nullptr) isLast = true;
		while(true) {
			addNode = new ListNode(ld1.val + ld2.val + extra);
			extra = 0;

			if ((*addNode).val >= 10)
			{
				(*addNode).val -= 10;
				extra++;
				if (isLast) {
					temp = ListNode();
					ld1.next = &temp;
					isLast = false;
				}
			}
			if (idx > 0) FindIndex(idx-1)[0].next = &(*addNode);
			else sum[0].val = (*addNode).val;

			idx++;

			if (isLast) break;
			if (ld1.next != nullptr) ld1 = *ld1.next;
			else ld1 = ListNode();
			if (ld2.next != nullptr) ld2 = *ld2.next;
			else ld2 = ListNode();
			if ((ld1.next == nullptr) && (ld2.next == nullptr)) isLast = true;
		} 
	}

	ListNode* AddTwoNumbers::FindIndex(int idx)
	{
		ListNode* nextNode = sum;
		
		if (idx == 0) nextNode = &sum[0];
		else {
			for (int cnt = 0; cnt < idx; cnt++) {
				nextNode = nextNode->next;
			}
		}

		return nextNode;
	}
}