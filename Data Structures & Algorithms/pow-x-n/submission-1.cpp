class Solution {
public:
    double myPow(double x, int n) {
        double sum = x;
        if(n==0){
            return 1;
        }
        for(int i =0;i<abs(n)-1;i++){
            sum *= x;
        }
        if(n<0){
            return 1/sum;
        }
        return sum;
    }
};
