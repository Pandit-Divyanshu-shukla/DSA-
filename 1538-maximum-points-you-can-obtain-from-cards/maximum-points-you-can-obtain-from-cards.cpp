class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int sum = 0;
        
        for(int i=size-k; i<size; i++){
            sum+=cardPoints[i];
        }

        int maxPoints = sum;

        int l=size-k, r=size-1;

        while(l<size){
            r = (r+1)%size;
            sum+=cardPoints[r];
            sum-=cardPoints[l];
            l++;
            maxPoints = max(maxPoints,sum);
        }

        return maxPoints;
    }
};