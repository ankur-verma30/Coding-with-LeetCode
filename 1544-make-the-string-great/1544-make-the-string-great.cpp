class Solution {
public:
    string makeGood(string s) {
        string ans = "";
		ans.push_back(s[0]);

		for(int i = 1 ; i < s.length() ; i++)
		{
			if(ans.length() == 0)
				ans.push_back(s[i]);
			else if(abs(ans[ans.length()-1] - s[i]) == 32)
				ans.pop_back();
			else if(ans[ans.length()-1] - 32 != s[i])
				ans.push_back(s[i]);
		}
		return ans;
    
    }
};