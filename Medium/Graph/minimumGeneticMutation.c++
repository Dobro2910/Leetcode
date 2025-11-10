class Solution {
public:
    int bfs(int startIndex, int endIndex, vector<vector<int>>& geneGraph) {
        vector<bool> visitedGene(geneGraph.size(), false);
        queue<pair<int, int>> geneToVisit;
        visitedGene[startIndex] = true;
        geneToVisit.push({startIndex, 0});

        while(!geneToVisit.empty()) {
            auto [currentGene, steps] = geneToVisit.front();
            geneToVisit.pop();

            cout << "currentGene: " << currentGene << "\n";

            if (currentGene == endIndex) {
                return steps;
            }

            for (auto gene: geneGraph[currentGene]) {
                if (visitedGene[gene] == false) {
                    visitedGene[gene] = true;
                    geneToVisit.push({gene, steps + 1});
                }
            }
        }

        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int startIndex = 0;
        int endIndex = -1;

        bank.insert(bank.begin(), startGene);
        for (int i = 0; i < bank.size(); ++i) {
            cout << "bank.size: " << i << "\n";
            if (bank[i] == endGene) {
                endIndex = i;
            }
        }

        if (endIndex == -1) {
            return -1;
        }

        vector<vector<int>> geneGraph(bank.size());

        for (int i = 0; i < bank.size(); ++i) {
            for (int j = i; j < bank.size(); ++j) {
                int diffCount = 0;
                for (int k = 0; k < 8; ++k) {
                    if (bank[i][k] != bank[j][k]) {
                        ++diffCount;
                    }
                }
                if (diffCount == 1) {
                    cout << "i:" << i << " j:" << j << "\n";
                    geneGraph[i].push_back(j);
                    geneGraph[j].push_back(i); 
                }
            }
        }

        cout << "startIndex: " << startIndex << "\n";
        cout << "endIndex: " << endIndex << "\n";

        int numberOfSteps = bfs(startIndex, endIndex, geneGraph);

        return numberOfSteps;
    }
};