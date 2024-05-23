#include <iostream>
#include <vector>

using namespace std;

double partition(std::vector<int>& v, int left, int right, int medianIndex) {
    int i = left, j = right;

    while (i < j) {
        if (v[i] < v[right]) {
            i++;
        } else {
            swap(v[i], v[j - 1]);
            j--;
        }
    }

    swap(v[j], v[right]);

    if (j == medianIndex) {
        if (v.size() % 2 == 0) {
            return (v[j] + v[j - 1]) / 2.0;
        } else {
            return v[j];
        }
    } else if (j > medianIndex) {
        return partition(v, left, j - 1, medianIndex);
    } else {
        return partition(v, j + 1, right, medianIndex);
    }
}

double getM(std::vector<int>& v) {
    int n = v.size();
    return partition(v, 0, n - 1, n / 2);
}

int main() {
    vector<int> v{ 9, 11 ,8, 1, 7, 5, 8, 4, 2, 10, 6};

    cout << "La mediana es: " << getM(v) << endl;
    return 0;
}
