class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.length();
        vector<int> freq(26,0);
        queue<int> q;

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            q.push(i);
            while(!q.empty() && freq[s[q.front()]-'a']>1){
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};