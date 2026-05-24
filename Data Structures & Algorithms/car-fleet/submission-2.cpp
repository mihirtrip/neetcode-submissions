class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,double>> cars;
        for (int i =0;i<position.size();i++){
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end());
        for(int i = cars.size()-1;i>=0;i--){
            double time  = cars[i].second;
            if(st.empty() || st.top()<time){
                st.push(time);
            }
        }
        return st.size();
    }
};
