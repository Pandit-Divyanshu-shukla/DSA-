class Solution {
public:
    string largestOddNumber(string num) {
        string maxOdd = "";
        int mx = INT_MIN;

        int size = 0;


        for(int i=num.length()-1; i>=0; i--){
            if((num[i]-'0')%2!=0){
                size = i+1;
                break;
            }
        }

        for(int i=0; i<size; i++){
            maxOdd+=num[i];
        }

        return maxOdd;
    }
};