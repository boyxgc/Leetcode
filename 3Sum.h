class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >res;
        sort(num.begin(), num.end());
        
        int size = num.size();
        for(int it1 = 0; it1 < size-2; ++it1) {
            int it2 = it1+1;
            int it3 = size-1;
            while(it2 < it3) {// 2 pointers, go from two ends to mid
                int sum = num[it1] + num[it2] + num[it3];
                if(sum == 0){
                    vector<int> tmp;
                    tmp.push_back(num[it1]);
                    tmp.push_back(num[it2]);
                    tmp.push_back(num[it3]);
                    sort(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                    
                    it2++; 
                    it3--;
                    while(it2 < it3 && num[it2] == num[it2-1])// remove duplicates
                        it2++;
                    while(it2 < it3 && num[it3] == num[it3+1])// remove duplicates
                        it3--;
                }else if(sum < 0){
                    it2++;
                }else{
                    it3--;
                }
            }
            while(it1 < size-2 && num[it1] == num[it1+1])// remove duplicates
                it1++;
        }
        return res;
    }
};