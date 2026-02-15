// User function Template for C++
int distinct(vector<int>& arr) {
    // Your code here
    unordered_set<int> st;
    for(int x: arr){
        st.insert(x);
    }
    return st.size();
}