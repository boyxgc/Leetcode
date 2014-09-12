/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int st_num = gas.size();
        int st = 0;
        while(st < st_num) {
            int have = gas[st];
            int need = cost[st];
            int go = st;
            while(have >= need) {
                if(go != st && go %(st_num) == st) return st;
                
                have = have - cost[go%st_num] + gas[(go+1)%st_num];
                need = cost[(go+1)%st_num];
                go++;
            }
            st = go + 1;
        }
        return -1;
    }
};