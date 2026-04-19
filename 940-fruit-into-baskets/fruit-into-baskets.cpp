class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l=0, r=0;

        unordered_map<int,int> mp; //type freq

        int maxFruits=0;

        while(r<n){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            r++;
            maxFruits = max(maxFruits,r-l);
        }

        return maxFruits;

    }
};