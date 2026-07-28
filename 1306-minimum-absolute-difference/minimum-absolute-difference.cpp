class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int md = INT_MAX;
        for(int i=1;i<n;i++)
        {
            md = min(md,(arr[i] - arr[i-1]));
        }
        vector<vector<int>> rs;
        for(int i=1;i<n;i++)
        {
            int diff = arr[i] - arr[i-1];

            if(diff == md)
            {
                rs.push_back({arr[i-1],arr[i]});
            }
        }
        return rs;


        
    }
};