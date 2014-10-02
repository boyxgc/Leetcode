class Solution {
public:
    void nextPermutation(vector<int> &num) {
        //find the a pair to swith, which is cloest to the end
        for(int left = num.size() -2; left >= 0; --left) {
            //find the smallest bigger one on the right, then sort the remain part
            int min_bigger = -1;
            for(int right = left + 1; right < num.size(); ++right) {
                if(num[right] > num[left]) {
                    if(min_bigger == -1 || num[right] < num[min_bigger]) {
                        min_bigger = right;
                    }
                }
            }
            if(min_bigger != -1) {
                int tmp = num[min_bigger];
                num[min_bigger] = num[left];
                num[left] = tmp;
                sort(num.begin()+left+1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
        return;
    }
};