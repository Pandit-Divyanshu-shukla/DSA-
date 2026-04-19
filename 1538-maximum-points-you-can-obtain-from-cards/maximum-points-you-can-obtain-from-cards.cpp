class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        // int maxScore = 0;
        int sum=0;
        for(int i=n-1; i>=n-k; i--){
            sum+=cardPoints[i];
        }

        int maxScore = sum;
        int l=n-k, r=n-1;

        while(l<n){
            sum -= cardPoints[l];
            sum += cardPoints[(r+1)%n];
            maxScore = max(maxScore,sum);
            l++; r++;
        }

        return maxScore;
    }
};