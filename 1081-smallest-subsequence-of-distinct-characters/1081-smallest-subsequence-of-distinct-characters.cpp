class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }
        string str;
        vector<int> arr(26,0);
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a']) continue;
            while(!st.empty() && st.top()>s[i] && mpp[st.top()]>i){
                 arr[st.top()-'a']=0;
                 st.pop();

            }
            st.push(s[i]);
            arr[s[i]-'a']=1;;
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
        
    }
};