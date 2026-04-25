// User function template for C
int largest(int arr[], int n) {
    // Code Here
    int mx = arr[0];
    for(int i=0; i<n; i++){
        if(mx<arr[i]){
            mx = arr[i];
        }
    }
    
    return mx;
}