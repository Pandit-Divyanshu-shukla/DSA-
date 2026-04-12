class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0, end=height.size()-1;
        int maxArea = INT_MIN;

        while(st<end){
            maxArea = max(maxArea, min(height[st],height[end])*(end-st));
            if(height[st]<height[end]) st++;
            else{ end--; }
        }

        return maxArea;
    }
};