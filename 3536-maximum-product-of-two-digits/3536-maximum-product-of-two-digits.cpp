class Solution {
public:
    int maxProduct(int n) {
    int p=n;
    int a=0;
    int b=0;
    while(p){
        int k=p%10;
        if(k>a){
            int t=a;
            a=k;
            b=t;
        }
        else if(k>b){
            b=k;
        }
        p/=10;
    }  
    return a*b;}
};