// Definition for Employee.
// class Employee {
//     public int id;
//     public int importance;
//     public List<Integer> subordinates;
// };


class Solution {
    int sumValue = 0;
	
	void dfs(List<Employee> employees, int id, int value) {
		Employee emp = new Employee();
		for(Employee employee:employees) {
			if(id==employee.id) {
				emp = employee;
				sumValue += employee.importance;
			}				
		}
		if(emp.subordinates.size() == 0) {
			return;
		}
		for(int i=0;i<emp.subordinates.size();i++) {
			dfs(employees, emp.subordinates.get(i), value);
		}
		
	}
	
    public int getImportance(List<Employee> employees, int id) {
    	dfs(employees, id, 0);
        return sumValue;
    }
}