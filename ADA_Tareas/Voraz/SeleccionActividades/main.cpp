#include <iostream>
#include <vector>
#include <algorithm>

struct Class {
    int start;
    int end;
    std::string name;
};

void printClasses(const std::vector<Class>& classes) {
    for (const auto& c : classes) {
        std::cout << c.name << "\n start: " << c.start << " - end: " << c.end << std::endl;
    }
}

void optimalSchedule(int n, std::vector<Class> classes) {
    std::sort(classes.begin(), classes.end(), [](const Class& a, const Class& b) { return a.end < b.end; });
    std::vector<Class> schedule = { classes[0] };
    int i = 1, prev = 0;

    while (i < n) {
        if (classes[i].start >= schedule[prev].end) {
            schedule.push_back(classes[i]);
            ++prev;
        }
        i++;
    }

    printClasses(schedule);

}

int main() {
    std::vector<Class> classes = {
        {1, 7, "A"},
        {2, 5, "B"},
        {4, 6, "C"},
        {4, 9, "D"},
        {5, 8, "E"},
        {6, 10, "F"},
        {7, 11, "G"},
        {9, 12, "H"}
    };
    int n = classes.size();

    optimalSchedule(n, classes);

    return 0;
}