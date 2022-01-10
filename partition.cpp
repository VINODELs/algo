#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

constexpr int RANDOM_SEED = 13337;
std::mt19937 gen(RANDOM_SEED);

void PrintVector(const std::vector<int>& array) {
    for (const int& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int GetPivot(int left, int right, const std::vector<int>& array) {
    std::uniform_int_distribution<int> dist(left, right - 1);
    int position = dist(gen);
    return position;
}

int Partition(int start, int end, std::vector<int>& array) {
    // returns the array index relative to which the partition
    // is performed (inplace)
    int pivot_pos = GetPivot(start, end, array);
    int pivot = array[pivot_pos];
    std::swap(array[pivot_pos], array[array.size() - 1]);
    int left = start;
    int right = start;
    
    while (right != end) {
        if (array[right] < pivot) {
            std::swap(array[left], array[right]);
            ++left;
        } else {
            if (!(left >= (right / 2) || (right == end - 1))) {
                std::swap(array[left], array[right]);
                ++left;
            }
        }
        ++right;
    }
    std::swap(array[array.size() - 1], array[left]);
    return left;
}

int main() {
    std::vector<int> array{42, 123, 664, 122, -123, 3145, 1124141, 12, 1, -123};
    int left = 0;
    int right = static_cast<int>(array.size());
    int index = Partition(left, right, array);
    PrintVector(array);
    return 0;
}
