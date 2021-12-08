public class Solution {
    public int solve(int A) {

        int result = 0;

        for(int i=1;i<=A/2;i++){
            if(A%i==0)result++;
        }

        return result;

    }
}