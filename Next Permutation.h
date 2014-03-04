class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if(size == 0) return;
        
        for(int i = size-2; i >= 0; --i){
            int maxmin = INT_MAX;
            int maxindex = -1;
            for(int j = i; j < size; ++j){
                if(num[j] > num[i] && num[j] < maxmin){
                    maxmin = num[j];// the least one greater than num[i]
                    maxindex = j;
                }
            }
            if(maxindex >= 0){// find greater element
                int tmp = num[i];
                num[i] = num[maxindex];
                num[maxindex] = tmp;
                sort(num.begin()+i+1, num.end());// sort part after i, mk sure mini greater
                return;
            }
        }
        
        sort(num.begin(), num.end()); //not found
        return;
    }
};