class Solution {
public:
   

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> temp = arr;
    
    // Step 1: Sort the copy
    sort(temp.begin(), temp.end());
    
    // Step 2: Assign ranks
    unordered_map<int, int> rank;
    int r = 1;
    
    for (int num : temp) {
        if (rank.find(num) == rank.end()) {
            rank[num] = r++;
        }
    }
    
    // Step 3: Replace values with rank
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rank[arr[i]];
    }
    
    return arr;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};
    vector<int> result = arrayRankTransform(arr);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
};