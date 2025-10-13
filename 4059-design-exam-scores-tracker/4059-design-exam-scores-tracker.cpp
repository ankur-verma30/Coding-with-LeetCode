class ExamTracker {
public:
    vector<int>timeCount;
    vector<long long>scores;
    long long sum;
    ExamTracker() {
        sum=0;
        timeCount.push_back(0);
        scores.push_back(sum);
    }
    
    void record(int time, int score) {
        sum+=score;
        timeCount.push_back(time);
        long long previousScore=scores.back();
        scores.push_back(score+previousScore);
        
    }
    
    long long totalScore(int startTime, int endTime) {
        // case 1: endTime is present in the map ex [1,5] [2,5]
        
            int startPos=(lower_bound(timeCount.begin(),timeCount.end(),startTime)-timeCount.begin())-1;
            int endPos=(upper_bound(timeCount.begin(),timeCount.end(),endTime)-timeCount.begin())-1;
            if(startPos<0) return scores[endPos];
            if(endPos<startPos) return 0;
            if(endPos<0) return 0;

            return scores[endPos]-scores[startPos];
            
     
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */