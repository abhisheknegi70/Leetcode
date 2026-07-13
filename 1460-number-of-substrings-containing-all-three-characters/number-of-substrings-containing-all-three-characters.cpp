class Solution {
public:
    int numberOfSubstrings(string s) {
        int lasts[3] = {-1,-1,-1};
        int cnt = 0;
        int n =s.size();
        for(int i=0;i<n;i++)
        {
            lasts[s[i] - 'a'] = i;
            if(lasts[0] != -1 && lasts[1] != -1 && lasts[2] != -1)
            {
                cnt += 1 + min({lasts[0], lasts[1], lasts[2]});
            }
        }
        return cnt;
        
    }
};