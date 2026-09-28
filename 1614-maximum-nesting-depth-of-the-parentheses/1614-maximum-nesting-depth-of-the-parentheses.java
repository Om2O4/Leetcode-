class Solution {
    public int maxDepth(String s) {
        int max=0,d=0;
        for(char ch:s.toCharArray()){
            d+=ch=='(' ? 1:ch==')'?-1:0;
            max=Math.max(max,d);
        }
        return max;
    }
}