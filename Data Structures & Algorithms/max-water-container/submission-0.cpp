class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int i = 0;
        int j = heights.size()-1;
        while(j>i){
            int ht = min(heights[i],heights[j]);
            int bt = j-i;
            int sum = ht*bt;
            maxi = max(sum,maxi);

            if(heights[i]>heights[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};
