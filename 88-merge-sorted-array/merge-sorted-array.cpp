class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;



        vector<int> n1;

        for(int i=0; i<m; i++){
            n1.push_back(nums1[i]);
        }

        int i=0; int j=0;

        int k=0;

        while(i<m && j<n){
            if(n1[i]<=nums2[j]){
                nums1[k++]=n1[i++];
            }else{
                nums1[k++] = nums2[j++];
            }
        }

        while(i<m){
            nums1[k++]=n1[i++];
        }

        while(j<n){
            nums1[k++] = nums2[j++];
        }

        return;
    }
};