class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int mx = arr[0];
        int s_mx = -1;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i]>mx){
                s_mx = mx;
                mx = arr[i];
            }
            if(arr[i]>s_mx && arr[i]<mx){
                s_mx = arr[i];
            }
        }
        
        return s_mx;
    }
};