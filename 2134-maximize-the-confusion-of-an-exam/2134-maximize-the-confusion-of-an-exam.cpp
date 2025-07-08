class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, maxAns = 1, n = answerKey.size();
        int tCount = 0, fCount = 0;

        for (int right = 0; right < n; right++) {
            answerKey[right] == 'T' ? tCount++ : fCount++;
            if (tCount <= k || fCount <= k)
                maxAns = max(maxAns, right - left + 1);
            else{
                    answerKey[left]=='T'? tCount-- : fCount--;
                    left++;
            }
        }

        return maxAns;
    }
};