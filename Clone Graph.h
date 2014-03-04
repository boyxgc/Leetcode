/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        map<int, UndirectedGraphNode*> nodeMap;
        unordered_set<int> visited;
        queue<pair<UndirectedGraphNode*,UndirectedGraphNode*>> toVisit;
    
        //copy first node
        UndirectedGraphNode* nodecopy = new UndirectedGraphNode(node->label);
        nodeMap[nodecopy->label] = nodecopy;
        toVisit.push({node, nodecopy});
        visited.insert(nodecopy->label);// mark visited
        
        while(!toVisit.empty()){
            pair<UndirectedGraphNode *, UndirectedGraphNode *>top = toVisit.front();
            toVisit.pop();
            
            UndirectedGraphNode *org = top.first;
            UndirectedGraphNode *cpy = top.second;
     
            //copy neighbors
            vector<UndirectedGraphNode *> neighborscopy;
            for(int i = 0; i < org->neighbors.size(); ++i){
                UndirectedGraphNode* tmp = org->neighbors[i];// org neigh
                UndirectedGraphNode* neigh = NULL; // new cpy neigh
                if(nodeMap.find(tmp->label) == nodeMap.end()){//not copied yet
                    neigh = new UndirectedGraphNode(tmp->label);
                    nodeMap[tmp->label] = neigh;
                } else {//already copied
                    neigh = nodeMap[tmp->label];
                }
                neighborscopy.push_back(neigh);
                
                //add to toVisit
                if(visited.find(neigh->label) == visited.end()){
                    visited.insert(neigh->label);
                    toVisit.push({tmp, neigh});
                }
            }
            cpy->neighbors = neighborscopy;
        }
        return nodecopy;
    }
};