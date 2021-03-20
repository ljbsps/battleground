class Solution {
private:
	bool ret = true;
	int numRoom;
	bool* isVisit;

public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		numRoom = rooms.size();
		isVisit = (bool*)calloc(numRoom, sizeof(bool));

		isVisit[0] = true;
		dfs(rooms, 0);
		for (int i = 0; i < numRoom; i++)
		{
			bool tmp = isVisit[i];
			if (isVisit[i] == false)
			{
				ret = false;
				break;
			}
		}

		return ret;
	}

	void dfs(vector<vector<int>>& rooms, int no)
	{
		for (vector<int>::iterator it = rooms[no].begin(); it != rooms[no].end(); it++)
		{
			if (isVisit[*it] == true) continue;
			else
			{
				isVisit[*it] = true;
				dfs(rooms, *it);
			}
		}
	}
};
