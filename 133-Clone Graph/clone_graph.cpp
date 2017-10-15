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
    map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return node;
        UndirectedGraphNode* cur_node = new UndirectedGraphNode(node->label);
        dict[node] = cur_node;
        for(int i = 0; i < node->neighbors.size(); i++){
            if(dict[node->neighbors[i]] == NULL){
                UndirectedGraphNode *temp = cloneGraph(node->neighbors[i]);
                cur_node->neighbors.push_back(temp);
            }
            else{
                cur_node->neighbors.push_back(dict[node->neighbors[i]]);
            }
        }
        return cur_node;
    }
};
