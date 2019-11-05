class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        addrs = []
        for email in emails:
            fields = email.split('@')
            # only one @ is guaranteed
            domainname = fields[1]
            localname = fields[0]
            finalname = ""
            for c in localname:
                if c == '.':
                    continue
                if c == '+':
                    break
                finalname += c
            finaladdr = finalname + '@' + domainname
            if not finaladdr in addrs:
                addrs.append(finaladdr)
        return len(addrs)
