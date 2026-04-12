class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int totalWater = 0;

        left[0] = right[n-1] = INT_MIN;

        for(int i=1; i<n; i++){
            left[i] = max(left[i-1],height[i-1]);
            right[n-i-1] = max(right[n-i],height[n-i]);
        }

        for(int i=0; i<n; i++){
            cout<<height[i]<<"->"<<left[i]<<" "<<right[i]<<endl;
        }

        for(int idx=1; idx<n-1; idx++){
            if(height[idx]>min(left[idx],right[idx])) continue;
            totalWater += min(left[idx],right[idx])-height[idx];
        }

        return totalWater;
    }
};