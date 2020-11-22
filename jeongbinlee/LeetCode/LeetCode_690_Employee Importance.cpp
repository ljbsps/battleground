class Solution {
private:
	int ret;
	vector<int> stack; 
	vector<Employee*> employeeList;
	
public:
	Solution()
	{
		ret = 0;
	}

	Employee getEmployeeById(int id)
	{
		Employee ret;

		for (int i = 0; i < employeeList.size(); i++)
		{
			if (employeeList.at(i)->id == id)
			{
				ret.id = employeeList.at(i)->id;
				ret.importance = employeeList.at(i)->importance;
				ret.subordinates = employeeList.at(i)->subordinates;
				break;
			}
		}

		return ret;
	}

	int getImportance(vector<Employee*> employees, int id) {
		int idx = 0;
		employeeList = employees;
		Employee who = getEmployeeById(id);
		ret += who.importance;

		bfs(who);

		for (int sum = 0; sum < stack.size(); sum++)
		{
			int imp = getEmployeeById(stack.at(sum)).importance;

			ret += imp;
		}
		
		return ret;
	}

	void bfs(Employee employee)
	{
		for (int sub = 0; sub < employee.subordinates.size(); sub++)
		{
			int subId = 0;
			if(employee.subordinates.size() > 0)
				subId = employee.subordinates.at(sub);
			if(!isExist(stack, subId))
				stack.push_back(subId);
			bfs(getEmployeeById(subId));
		}
	}

	bool isExist(vector<int> stack, int find)
	{
		for (int i = 0; i < stack.size(); i++)
			if (stack.at(i) == find)
				return true;

		return false;
	}
};
