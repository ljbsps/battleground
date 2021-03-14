class Solution {
	ListNode* ret;
	vector<ListNode*> vec;

public:
	ListNode* swapNodes(ListNode* head, int k) {
		ListNode* temp;
		int size, val;

		temp = head;
		while (true)
		{
			vec.push_back(temp);
			if (temp->next != nullptr)
				temp = temp->next;
			else
				break;
		}
		size = vec.size();

		val = vec[k - 1]->val;
		vec[k - 1]->val = vec[(size - 1) - (k - 1)]->val;
		vec[(size - 1) - (k - 1)]->val = val;
		ret = vec[0];

		return ret;
	}
};
