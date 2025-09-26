#include <iostream>
#include <set>
#include <random>

class RandomizedSet {
public:
    std::set<int> mySet;

    RandomizedSet() : mySet() {}   // constructor initializes the set

    bool insert(int val) {
        // insert() returns a pair: (iterator, bool)
        auto result = mySet.insert(val);
        return result.second; // true if inserted, false if already existed
    }

    bool remove(int val) {
        // erase() returns the number of elements erased (0 or 1)
        return mySet.erase(val) > 0;
    }

    int getRandom() {
        if (mySet.empty()) {
            throw std::runtime_error("Set is empty!"); // better than returning false
        }

        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<> dist(0, mySet.size() - 1);
        int randomIndex = dist(gen);

        auto it = mySet.begin();
        std::advance(it, randomIndex);

        return *it;
    }
};

/**
 * Example usage:
int main() {
    RandomizedSet* obj = new RandomizedSet();
    std::cout << obj->insert(10) << "\n";  // true
    std::cout << obj->insert(20) << "\n";  // true
    std::cout << obj->insert(10) << "\n";  // false (already exists)
    std::cout << obj->remove(20) << "\n";  // true
    std::cout << obj->remove(30) << "\n";  // false (not found)
    std::cout << obj->getRandom() << "\n"; // random element
}
 */
