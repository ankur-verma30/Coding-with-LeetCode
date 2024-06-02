class Solution {
public:
    int minimumChairs(string s) {
              int current_people = 0;
    int max_people = 0;

    for(char c : s) {
        if(c == 'E') {
            current_people++;
        } else if(c == 'L') {
            current_people--;
        }
        max_people = max(max_people, current_people);
    }

    return max_people;
    }
};