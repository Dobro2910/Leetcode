class Solution {
public:
    int bfs(int startingPoint, int totalNumberOfNodes, vector<vector<int>>& adjacencyList) {
        vector<int> parent(totalNumberOfNodes + 1, -1);
        vector<bool> visitedNodes(totalNumberOfNodes + 1, false);
        queue<int> nodeToVisit;

        nodeToVisit.push(startingPoint);
        visitedNodes[startingPoint] = true;
        
        while (!nodeToVisit.empty()) {
            int currentNode = nodeToVisit.front();
            nodeToVisit.pop();

            if (currentNode == totalNumberOfNodes) {
                break;
            }

            for (auto node : adjacencyList[currentNode]) {
                if (visitedNodes[node] == false) {
                    parent[node] = currentNode;

                    nodeToVisit.push(node);
                    visitedNodes[node] = true;
                }
            }
        }

        if (parent[totalNumberOfNodes] == -1) {
            return -1;
        }

        vector<int> path;
        for (int node = totalNumberOfNodes; node != -1; node = parent[node]) {
            cout << "path node: " << node << "\n";
            path.push_back(node);
        }
        
        return path.size() - 1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int totalNumberOfNodes = n * n;
        int curr = 1;
        map<int, int> snakeLadderMapping;

        for (int i = n - 1; i >= 0; --i) {
            int rowFromBottom = n - 1 - i;
            if (rowFromBottom % 2 != 0) {
                for (int j = n - 1; j >= 0; --j) {
                    if (board[i][j] != -1) {
                        snakeLadderMapping.insert({curr, board[i][j]});
                    }
                    ++curr;
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] != -1) {
                        snakeLadderMapping.insert({curr, board[i][j]});
                    }
                    ++curr;
                }
            }
        }

        curr = 1;
        vector<vector<int>> adjacencyList(totalNumberOfNodes + 1);
        for (int i = n - 1; i >= 0; --i) {
            int rowFromBottom = n - 1 - i;
            if (rowFromBottom % 2 != 0) {
                for (int j = n - 1; j >= 0; --j) {
                    cout << "curr " << curr << " : ";
                    for (int k = 1; k < 7; ++k) {
                        if (curr + k <= totalNumberOfNodes) {
                            if (snakeLadderMapping.find(curr + k) != snakeLadderMapping.end()) {
                                cout << snakeLadderMapping[curr + k] << " ";
                                adjacencyList[curr].push_back(snakeLadderMapping[curr + k]);
                            } else {
                                cout << curr + k << " ";
                                adjacencyList[curr].push_back(curr + k);
                            }
                        }
                    }
                    cout << "\n";
                    ++curr;
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    cout << "curr " << curr << " : ";
                    for (int k = 1; k < 7; ++k) {
                        if (curr + k <= totalNumberOfNodes) {
                            if (snakeLadderMapping.find(curr + k) != snakeLadderMapping.end()) {
                                cout << snakeLadderMapping[curr + k] << " ";
                                adjacencyList[curr].push_back(snakeLadderMapping[curr + k]);
                            } else {
                                cout << curr + k << " ";
                                adjacencyList[curr].push_back(curr + k);
                            }
                        }
                    }
                    cout << "\n";
                    ++curr;
                }
            }
        }

        int numberOfTurns = bfs(1, totalNumberOfNodes, adjacencyList);

        return numberOfTurns;
    }
};
