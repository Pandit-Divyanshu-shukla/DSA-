class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        if(arr.size()==1){
            return -1;
        }
        // code here
        int max = arr[0];
        int max_2 = -1;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i]>max){
                max_2 = max;
                max = arr[i];
            }
            else if(arr[i]>max_2 && arr[i]<max){
                max_2 = arr[i];
            }
        }
        
        return max_2;
    }
};