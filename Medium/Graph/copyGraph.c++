class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        unordered_map<Node *, Node *> copies;
        return clone(node, copies);
    }

private:
    Node *clone(Node *node, unordered_map<Node *, Node *> &copies)
    {
        if (!node)
            return nullptr;

        if (copies.find(node) != copies.end())
            return copies[node];

        Node *newNode = new Node(node->val);
        copies[node] = newNode;

        for (Node *neighbor : node->neighbors)
        {
            newNode->neighbors.push_back(clone(neighbor, copies));
        }

        return newNode;
    }
};