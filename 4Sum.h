class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        vector<vector<int> > res;
        int size = num.size();
        for(int p1 = 0; p1 < size - 3; ++p1) {
            if(p1 > 0 && num[p1] == num[p1-1]) continue;
            for(int p2 = p1+1; p2 < size - 2; ++p2) {
                if(p2 > p1+1 && num[p2] == num[p2-1]) continue;
                
                int p3 = p2+1;
                int p4 = size-1;
                while(p3 < p4) {
                    if(p3 > p2+1 && num[p3] == num[p3-1]) {p3++; continue;}
                    if(p4 < size-1 && num[p4] == num[p4+1]) {p4--; continue;}
                    
                    int sum = num[p1] + num[p2] + num[p3] + num[p4];
                    if(sum == target) {
                        vector<int> v;
                        v.push_back(num[p1]);
                        v.push_back(num[p2]);
                        v.push_back(num[p3]);
                        v.push_back(num[p4]);
                        res.push_back(v);
                        p3++;
                        p4--;
                    } else  if(sum > target) {
                        p4--;
                    } else {
                        p3++;
                    }
                }
            }
        }
        
        return res;
    }
};