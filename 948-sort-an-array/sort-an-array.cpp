class Solution {
public:
    void heapify(int idx,vector<int> &vec,int n)
{
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < n && vec[l] > vec[largest])
    {
        largest = l;
    }
    if (r < n && vec[r] > vec[largest])
    {
        largest = r;
    }

    if (largest != idx)
    {
        swap(vec[largest], vec[idx]);
    }
    else{
        return;
    }
    heapify(largest,vec,n);
}

void fixHeap(vector<int> &vec,int n){
    cout<<"Before heap is fixed"<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1; i>=0; i--){
        swap(vec[0],vec[i]);
        heapify(0,vec,i);
    }
    cout<<"After heap is fixed"<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

vector<int> sortArray(vector<int> &vec)
{
    int n = vec.size();
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(i,vec,n);
    }
    fixHeap(vec,n);
    return vec;
}
};