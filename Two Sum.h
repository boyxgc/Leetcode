/*
Description:
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        int size = numbers.size();
        map<int, int> indexMap;// only one solution, so just num:index mapping is enough
        for(int i = 0; i < size; ++i)
            indexMap[numbers[i]] = i;
        for(int i = 0; i < size; ++i){
            if(indexMap.find(target-numbers[i]) != indexMap.end()){
                if(indexMap[target-numbers[i]] != i){
                    int first = min(i, indexMap[target-numbers[i]]);
                    int second = max(i, indexMap[target-numbers[i]]);
                    ret.push_back(first+1);
                    ret.push_back(second+1);
                    return ret;
                }
            }
        }
        return ret;
    }
};
