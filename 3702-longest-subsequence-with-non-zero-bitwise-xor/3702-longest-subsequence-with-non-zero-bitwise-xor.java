class Solution {
    public int longestSubsequence(int[] n) {
        int xor=0;
        boolean nz=false;

        for(int x:n){
            xor^=x;
            if(x!=0){
                nz=true;
            }
        }

        if(xor!=0){
            return n.length;
        }

        if(nz){
            return n.length-1;
        }
        return 0;
    }
}