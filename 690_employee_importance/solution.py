"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
def employee_of(employees, id):
    for e in employees:
        if e.id == id:
            return e
class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        e = employee_of(employees, id)
        if not e:
            return 0
        ret = e.importance
        employees.remove(e)
        subords = e.subordinates
        while len(subords) > 0:
            next_subords = []
            for i in subords:
                subords.remove(i)
                e = employee_of(employees, i)
                if not e:
                    continue
                ret += e.importance
                next_subords += e.subordinates
            subords += next_subords
        return ret
