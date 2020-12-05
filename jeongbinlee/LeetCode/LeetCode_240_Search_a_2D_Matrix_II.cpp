class Solution {
private:
	bool ret;
	int m;
	int n;
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		m = matrix.size();
		n = matrix.front().size();

		ret = divideSearch(matrix, target, 0, m - 1, 0, n - 1);

		return ret;
	}

	bool divideSearch(vector<vector<int>>& subMat, int target, int startm, int endm, int startn, int endn)
	{
		bool ret = false;
		int row = endm - startm;
		int col = endn - startn;

		int piv = 0, base = 0, ms, me, ns, ne;


		if (row == 0 && col == 0)
		{
			if (subMat.at(endm).at(endn) == target) ret = true;
			else ret = false;
			return ret;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			if (dir == 2 && row == 0) continue;
			else if (dir == 3 && col == 0) continue;
			if (dir == 0)
			{
				ms = startm;
				me = startm + (row + 1) / 2 - 1;
				ns = startn;
				ne = startn + (col + 1) / 2 - 1;
			}
			else if (dir == 1)
			{
				ms = startm;
				me = startm + (row + 1) / 2 - 1;
				ns = startn + (col + 1) / 2;
				ne = startn + col;
			}
			else if (dir == 2)
			{
				ms = startm + (row + 1) / 2;
				me = startm + row;
				ns = startn;
				ne = startn + (col + 1) / 2 - 1;
			}
			else if (dir == 3)
			{
				ms = startm + (row + 1) / 2;
				me = startm + row;
				ns = startn + (col + 1) / 2;
				ne = startn + col;
			}
			if (row == 0) me = ms;
			if (col == 0)ne = ns;
			if (ms < 0 || me < 0 || ns < 0 || ne < 0) continue;
			piv = subMat.at(me).at(ne);
			base = subMat.at(ms).at(ns);

			if (piv == target || base == target) return true;
			else if (piv > target && base < target)
			{
				ret = divideSearch(subMat, target, ms, me, ns, ne);
			}

			if (ret)
				break;
		}

		return ret;
	}
};
