// https://www.interviewbit.com/problems/subarray-with-given-xor/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int solve(int* A, int n1, int B) {
    int ans = 0;
    for(int i = 0; i < n1; ++i) {
        int xor = 0;
        for(int j = i; j < n1; ++j){
            xor ^= A[j];

            if(xor == B) {
                cnt++;
            }
        }
    }
    return cnt;
}
