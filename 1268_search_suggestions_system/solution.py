class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """
        products = sorted(products)
        list_suggestions = []
        for i in range(len(searchWord)):
            suggestion = []
            for p in products:
                if p.startswith(searchWord[:i + 1]):
                    suggestion.append(p)
                    if len(suggestion) == 3:
                        break
            list_suggestions.append(suggestion)
        return list_suggestions
