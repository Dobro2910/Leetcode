class Solution
{
    unordered_map<string, unordered_map<string, double>> graph;

private:
    bool dfs(const string &stringStart, const string &stringEnd, unordered_set<string> &visited, double &value)
    {
        if (graph.find(stringStart) == graph.end())
        {
            return false;
        }

        if (stringStart == stringEnd)
        {
            return true;
        }

        visited.insert(stringStart);

        for (const auto &[neighbor, weight] : graph[stringStart])
        {
            if (visited.find(neighbor) == visited.end())
            {
                double nextValue = value * weight;
                bool result = dfs(neighbor, stringEnd, visited, nextValue);
                if (result == true)
                {
                    value = nextValue;
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
    std:
        vector<double> result;

        for (int i = 0; i < equations.size(); ++i)
        {
            string A = equations[i][0];
            string B = equations[i][1];
            double inputValue = values[i];

            graph[A][B] = inputValue;
            graph[B][A] = 1 / inputValue;
        }

        for (int i = 0; i < queries.size(); ++i)
        {
            if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end())
            {
                result.push_back(-1);
                continue;
            }

            double value = 1.0;
            unordered_set<string> visited;
            if (dfs(queries[i][0], queries[i][1], visited, value))
            {
                result.push_back(value);
            }
            else
            {
                result.push_back(-1);
            }
        }

        return result;
    }
};