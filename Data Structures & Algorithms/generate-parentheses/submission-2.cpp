class Solution {
public:
    string temp = "";
    vector<string>ans;
    void back(string temp,int close, int open, int n){
        if(close>open || temp.length()>2*n){
            return;
        }
        if(open>n || close>n){
            return;
        }
        if(temp.length()==2*n && open == close){
            ans.push_back(temp);
            return;
        }

        
        back(temp+"(", close, open+1,n);
        if(open>=close){
            back(temp+")",close+1,open,n);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int close = 0;
        int open = 0;
        back(temp,close, open, n);
        return ans;
    }
};
