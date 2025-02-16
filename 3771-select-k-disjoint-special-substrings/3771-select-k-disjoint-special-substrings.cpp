class Solution {
public:
  bool maxSubstringLength(string s, int k) {
    int n = s.size();
    unordered_map<char, int> firstOccurrence, lastOccurrence;
    vector<pair<int, int>> intervals;

    for (int i = 0; i < n; i++) {
      if (!firstOccurrence.count(s[i])) firstOccurrence[s[i]] = i;
      lastOccurrence[s[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      if (i != firstOccurrence[s[i]]) continue;
      int left = firstOccurrence[s[i]], right = lastOccurrence[s[i]];
      bool isValid = true;
      for (int j = left; j <= right; j++) {
        right = max(right, lastOccurrence[s[j]]);
        if (firstOccurrence[s[j]] < left) isValid = false;
      }
      if (right - left + 1 < n && isValid) intervals.push_back({left, right});
    }

    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

    int count = 0, lastEnd = -1;
    for (auto &[start, end] : intervals) {
      if (start > lastEnd) {
        count++;
        lastEnd = end;
      }
    }
    
    return (count >= k);
  }
};