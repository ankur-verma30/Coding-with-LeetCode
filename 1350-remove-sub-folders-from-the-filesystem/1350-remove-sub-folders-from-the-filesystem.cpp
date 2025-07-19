class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_set<string> st;
        vector<string> ans;

        for (const string& path : folder) {
            string temp;
            bool isSubfolder = false;

            for (int i = 1; i < path.size(); ++i) {
                if (path[i] == '/') {
                    temp = path.substr(0, i);
                    if (st.count(temp)) {
                        isSubfolder = true;
                        break;
                    }
                }
            }

            if (!isSubfolder) {
                st.insert(path);
                ans.push_back(path);
            }
        }

        return ans;
    }
};
