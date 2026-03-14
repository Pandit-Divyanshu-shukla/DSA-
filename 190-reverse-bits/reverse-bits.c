int reverseBits(int n) {

    int rev = 0;

    for(int i=0; i<32; i++){

        int curr = (n>>i) & 1;
        int mirrPos = 32-i-1;

        if(curr){
            rev = rev | (1<<mirrPos);
        }
        
    }

    return rev;
}