class Solution {
public:
    bool isPowerOfThree(int n) {
    long long x=pow(3,30);
    if(n<=0){
        return false; 
    }
    if(x%n==0 )
    {
        return true;
    }

    return false;
    }
};