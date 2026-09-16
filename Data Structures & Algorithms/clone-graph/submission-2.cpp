class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        std::unordered_map<Node*, Node*> clones;
        std::queue<Node*> q;

        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* nei : curr->neighbors) {

                // Haven't cloned this node yet
                if (clones.find(nei) == clones.end()) {
                    clones[nei] = new Node(nei->val);
                    q.push(nei);
                }

                // Connect cloned curr to cloned neighbor
                clones[curr]->neighbors.push_back(clones[nei]);
            }
        }

        return clones[node];
    }
};