class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        int size = num.size();
        vector<int> tmpv;
        for(int i = 0; i < size-3; ++i) {
            if(i > 0 && num[i] == num[i-1])// remove duplicate
                continue;
            for(int j = i+1; j < size-2; ++j) {
                if(j > i+1 && num[j] == num[j-1])// remove duplicate
                    continue;
                int l = j+1;
                int r = size-1;
                while(l < r) {
                    if(l > j+1 && num[l] == num[l-1]){// remove duplicate
                        l++;
                        continue;
                    }
                    if(r < size-1 && num[r] == num[r+1]){// remove duplicate
                        r--;
                        continue;
                    }
                    int tmp = num[i]+num[j]+num[l]+num[r];
                    if(tmp < target){
                        l++;
                    } else if (tmp > target){
                        r--;
                    } else {
                        tmpv.clear();
                        tmpv.push_back(num[i]);
                        tmpv.push_back(num[j]);
                        tmpv.push_back(num[l]);
                        tmpv.push_back(num[r]);
                        ret.push_back(tmpv);
                        l++;
                        r--;
                    }
                }
            }
        }
        return ret;
    }
};