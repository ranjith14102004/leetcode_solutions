class Solution {
public:
    long long sumAndMultiply(int n) {
        int p=n;
        int sum=0;
        int rev=0;
        while(p){
            int k=p%10;
            if(k){
                sum+=k;
                rev=(rev*10)+k;
            }
            p/=10;
        }
        int org=0;
        while(rev){
            int k=rev%10;
            org=(org*10)+k;
            rev/=10;
        }
    return (long long)sum*org;}
};