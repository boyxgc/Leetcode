class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
       sort(num.begin(), num.end());
       
       int size = num.size();
       int optsofar = num[0]+num[1]+num[2];
       for(int it1 = 0; it1 < size; ++it1) {
           int it2 = it1 + 1;
           int it3 = size -1;
           while(it2 < it3) {
                int sum = num[it1] + num[it2] + num[it3];
                if(abs(sum - target) < abs(optsofar - target))
                    optsofar = sum;
                    
                if(sum < target) {
                    it2++;
                } else if( sum == target) {
                    return target;
                } else {
                    it3--;
                }
           }
       }
       return optsofar;
    }
};