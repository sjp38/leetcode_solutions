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
class Solution(object):
    def employee_of(self, id):
        if id in self.emap:
            return self.emap[id]
        for e in self.elist:
            self.emap[e.id] = e
            if e.id == id:
                self.elist.remove(e)
                return e
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        self.emap = {}
        self.elist = employees
        e = self.employee_of(id)
        if not e:
            return 0
        ret = e.importance
        subords = e.subordinates
        while len(subords) > 0:
            next_subords = []
            for i in subords:
                subords.remove(i)
                e = self.employee_of(i)
                if not e:
                    continue
                ret += e.importance
                next_subords += e.subordinates
            subords += next_subords
        return ret
