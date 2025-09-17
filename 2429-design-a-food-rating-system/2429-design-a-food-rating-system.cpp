class FoodRatings {
    struct Compare{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        }
    };
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>> cuisineToFoods;


public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineToFoods[cuisine].push({rating, food});
            

        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        foodToRating[food] = newRating;
        cuisineToFoods[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
         auto &pq = cuisineToFoods[cuisine];
        while (!pq.empty()) {
            auto [rating, food] = pq.top();
            if (foodToRating[food] == rating) return food; 
            pq.pop(); 
        }
        return ""; 
    }
};
