class Solution:
    def minOperations(self, s: str) -> int:
        count = 0

        for i in range(1, len(s)):
            if s[i - 1] == s[i]:
                if s[i - 1] == '0':
                    s = s[:i] + '1' + s[i + 1:]
                    count += 1
                elif s[i - 1] == '1':

                    s = s[:i] + '0' + s[i + 1:]
                    count += 1
                

        return min(count, len(s) - count)

        