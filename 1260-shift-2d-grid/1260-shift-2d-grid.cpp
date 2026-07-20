class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int whole=k%(grid[0].size());
        int m=grid.size();
        int n=grid[0].size();
        // while(whole){
        //     int arr[]=grid[m-1];
        //     for(int i=0;i<m-1;i++){
        //         grid[i+1]=grid[i];
        //     }
        //     grid[[0]=arr;
        //     whole--;
        // }
        int s=grid[m-1][n-1];
        int t;
        while(k!=0){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                t=grid[i][j];
                grid[i][j]=s;
                s=t;

            }
        }
        s=grid[m-1][n-1];
        k--;}
return grid;
    }
};