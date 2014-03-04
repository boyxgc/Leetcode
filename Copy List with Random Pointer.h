/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<int, RandomListNode*> nodes;
        return dfsCopy(head, nodes);
    }
    RandomListNode *dfsCopy(RandomListNode *head, map<int, RandomListNode *>& nodes){
        if(!head) return NULL;
        if(nodes.find(head->label) != nodes.end()){
            return nodes[head->label];
        }
        RandomListNode * n = new RandomListNode(head->label);
        nodes[n->label] = n;
        n->next = dfsCopy(head->next, nodes);
        n->random = dfsCopy(head->random, nodes);
        return n;
    }
};