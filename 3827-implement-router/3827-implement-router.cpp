class Router {
private:

    int memoryLimit;
    queue<vector<int>> queue;
    unordered_set<string> packetSet;
    unordered_map<int, vector<int>> destinationTimestamps;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string tempHash=to_string(source)+"-"+
        to_string(destination)+"-"+to_string(timestamp);

        if (packetSet.count(tempHash)) return false;

        if (queue.size() >= memoryLimit) {
            vector<int>temp= queue.front();
            queue.pop();
            string canHash=to_string(temp[0])+"-"+
        to_string(temp[1])+"-"+to_string(temp[2]);
            packetSet.erase(canHash);
            destinationTimestamps[temp[1]].
                erase(destinationTimestamps[temp[1]].begin());
        }

        queue.push({source,destination,timestamp});
        packetSet.insert(tempHash);
        destinationTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (queue.empty()) return {};

        vector<int> packet = queue.front();
        queue.pop();
         string canHash=to_string(packet[0])+"-"+
        to_string(packet[1])+"-"+to_string(packet[2]);
        packetSet.erase(canHash);
        destinationTimestamps[packet[1]].
            erase(destinationTimestamps[packet[1]].begin());
        return {packet[0], packet[1], packet[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& timestamps = destinationTimestamps[destination];
        return count_if(timestamps.begin(), timestamps.end(), [&](int t) {
            return t >= startTime && t <= endTime;
        });
    }
};
/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */