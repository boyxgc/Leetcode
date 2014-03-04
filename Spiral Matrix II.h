class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> v(n, 0);
        vector<vector<int> >res(n, v);
        
        int deltai = 0;
        int deltaj = 1;
        int total = n*n;
        int count = 0;
        int i = 0, j = 0;
        
        while((++count) <= total) {
            if(i >= n || j >= n || i < 0 || j < 0)
                break;
            res[i][j] = count;
            
            int tmpi = i + deltai;
            int tmpj = j + deltaj;

            if(tmpj >= n || tmpi >= n || tmpj < 0 || tmpi < 0 || res[tmpi][tmpj] != 0) {
                change(deltai, deltaj);
            }
            
            i += deltai;
            j += deltaj;
            
        }
        
        return res;
    }
    
    void change(int &deltai, int &deltaj){
        if(deltai == 0 && deltaj == 1) {
            deltai = 1;
            deltaj = 0;
        } else if(deltai == 1 && deltaj == 0) {
            deltai = 0;
            deltaj = -1;
        } else if(deltai == 0 && deltaj == -1) {
            deltai = -1;
            deltaj = 0;
        } else {
            deltai = 0;
            deltaj = 1;
        }
        return;
    }
};