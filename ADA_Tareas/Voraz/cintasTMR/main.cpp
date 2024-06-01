#include <iostream>
#include <vector>
#include <algorithm>

struct File {
    int length;
    int index;
};

bool compareFiles(const File& a, const File& b) {
    return a.length < b.length;
}

double calculateTMR(const std::vector<File>& files) {
    int totalLength = 0;
    double totalTime = 0;

    for (const auto& file : files) {
        std::cout << "File " << file.index + 1 << " (L: " << file.length << ")" << std::endl;
        totalLength += file.length;
        totalTime += totalLength;
    }

    return totalTime / files.size();
}

void optimalPermutation(int n, const std::vector<int>& lengths) {
    std::vector<File> files(n);

    for (int i = 0; i < n; ++i) {
        files[i] = { lengths[i], i };
    }

    sort(files.begin(), files.end(), compareFiles);

    double tmr = calculateTMR(files);
    std::cout << "TMR minimo: " << tmr << std::endl;
}

int main() {
    std::vector<int> lengths = { 5, 10, 3 };
    int n = lengths.size();

    optimalPermutation(n, lengths);

    return 0;
}
