class Solution {
public:
    int minPartitions(string n) {
        int count=0;

        for(int i=0;i<n.length();i++){
            int number=n[i]-'0';
            count=max(count,number);
        }

        return count;
    }
};