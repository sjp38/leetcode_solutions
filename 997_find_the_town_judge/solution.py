class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        if len(trust) == 0 and N == 1:
            return 1
        # person -> people who the person is trusting
        tmap = {}
        # person -> people who trust the person
        trmap = {}
        for t in trust:
            if not t[0] in tmap:
                tmap[t[0]] = []
            tmap[t[0]].append(t[1])
            if not t[1] in trmap:
                trmap[t[1]] = []
            trmap[t[1]].append(t[0])
        people = range(1, N + 1)
        alltrusts = [x for x in trmap if sorted(trmap[x]) == [y for y in people if y != x]]
        judges = [x for x in alltrusts if not x in tmap]
        if len(judges) == 0:
            return -1
        return judges[0]
