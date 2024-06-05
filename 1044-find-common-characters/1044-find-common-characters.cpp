class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

    // Step 2: Iterate through each word in the input list.
    for (const string& word : words) {
        vector<int> freq(26, 0);
        
        // Step 3: Count the frequency of each character in the current word.
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Step 4: Update the minimum frequency array.
        for (int i = 0; i < 26; ++i) {
            minFreq[i] = min(minFreq[i], freq[i]);
        }
    }

    // Step 5: Prepare the result list based on the minimum frequency array.
    vector<string> result;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < minFreq[i]; ++j) {
            result.push_back(string(1, 'a' + i));
        }
    }

    return result;
    }
};