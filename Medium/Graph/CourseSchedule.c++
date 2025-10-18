#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build graph and indegree array
        vector<vector<int>> graph(numCourses); // adjacency list: graph[i] = courses that depend on i
        vector<int> indegree(numCourses, 0);   // indegree[i] = number of prerequisites for course i

        for (auto &p : prerequisites) {
            // p[1] -> p[0]: to take course p[0], you need to finish p[1]
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++; // increase the prerequisite count for course p[0]
        }

        // Step 2: Initialize queue with courses that have no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i); // courses with indegree 0 can be taken immediately
            }
        }

        // Step 3: Process courses in topological order
        int processed = 0; // count how many courses we can take
        while (!q.empty()) {
            int curr = q.front(); // take the course at the front of the queue
            q.pop();
            processed++;          // we "take" this course

            // Reduce indegree of all courses that depend on current course
            for (int next : graph[curr]) {
                indegree[next]--;        // one prerequisite is completed
                if (indegree[next] == 0) {
                    q.push(next);        // course is ready to take, add to queue (This is adding new courses to the queue right here !!!)
                }
            }
        }

        // Step 4: Check if all courses were processed
        // If processed == numCourses, we were able to take all courses (no cycles)
        // If not, there is a cycle and some courses can't be completed
        return processed == numCourses;
    }
};
