class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> directedGraph(numCourses);
        vector<int> coursePrerequisitesCount(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            directedGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++coursePrerequisitesCount[prerequisites[i][0]];
        }

        queue<int> coursesToTake;
        for (int i = 0; i < numCourses; ++i) {
            if (coursePrerequisitesCount[i] == 0) {
                cout << "coursesToTake: " << i << "\n";
                coursesToTake.push(i);
            }
        }
        
        int numberOfCoursesHaveTaken = 0;
        vector<int> coursesReturnOrder;
        while (!coursesToTake.empty()) {
            int currentCourse = coursesToTake.front();
            coursesReturnOrder.push_back(currentCourse);
            ++numberOfCoursesHaveTaken;
            coursesToTake.pop();

            for (auto course : directedGraph[currentCourse]) {
                cout << "course: " << course << "\n";
                --coursePrerequisitesCount[course];

                if (coursePrerequisitesCount[course] == 0) {
                    coursesToTake.push(course);
                }
            }
        }

        if (numberOfCoursesHaveTaken < numCourses) {
            return {};
        }

        return coursesReturnOrder;
    }
};