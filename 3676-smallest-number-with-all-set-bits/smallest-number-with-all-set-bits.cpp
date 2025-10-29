class Solution {
public:
    int smallestNumber(int n) {
        int t= log(n)/log(2);
        int closetSmallestNumber=pow(2,t+1)-1;
        return closetSmallestNumber;
        
    }
};