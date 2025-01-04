class TaskManager {
   unordered_map<int, pair<int, int>> task;
    struct cmp {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second.first < b.second.first;
        }
    };

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];
            task[taskId] = make_pair(userId,priority);
            pq.push({priority, {taskId, userId}});
        }
    }

    void add(int userId, int taskId, int priority) {
     task[taskId] = {userId, priority};
        pq.push({priority, {taskId, userId}});
    }

    void edit(int taskId, int newPriority) {
        if (task.find(taskId) != task.end()) {
            pair<int, int> temp = task[taskId];
            task.erase(taskId);
            task[taskId] = {temp.first, newPriority};
            pq.push({newPriority, {taskId, temp.first}});
        }
    }

    void rmv(int taskId) { task.erase(taskId); }

    int execTop() {
             while (!pq.empty()) {
            auto it = pq.top();
            int priority = it.first;
            int taskId = it.second.first;
            int userId = it.second.second;
            pq.pop();
            if (task.find(taskId) != task.end() && task[taskId].second == priority) {
                task.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */