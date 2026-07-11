class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);

        for(int i =n-1;i>=0;i--){
            int digit_1 = num1[i] - '0';
            for(int j = m-1;j>=0;j--){
                int digit_2 = num2[j] - '0';
                int p1  = i+j+1;
                int p2 = i+j;
                int sum  = digit_1 * digit_2 + result[p1];
                result[p1] = sum%10;
                result[p2] += sum/10;
            }
        }
        string ans;
        int i = 0;
        while(i<result.size()&&result[i]==0){
            i++;
        }
        while(i<result.size()){
            ans.push_back(result[i]+'0');
            i++;
        }
        return ans;
    }
};
