class Solution {
public:
    
    string addBinary(string a, string b) {

        string ans = "";

        int n = max(a.size(),b.size());

        int i = a.size()-1;
        int j = b.size()-1;

        int carry=0;

        while(i>=0 || j>=0 || carry){
            int sum=0;

            if(i>=0) sum+=(a[i--]-'0');
            if(j>=0) sum+=(b[j--]-'0');

            sum+=carry;
            carry = sum/2;

            ans = char(sum%2 + '0') + ans;
        }

        // ans = char(carry) + ans;

        return ans;
    }
};