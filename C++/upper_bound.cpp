#include <algorithm>
#include <iostream>
#include <vector>

template <typename RandomAccessIter, typename ValueType>
RandomAccessIter UpperBound(RandomAccessIter first, RandomAccessIter last, ValueType target) {
    RandomAccessIter left = first;
    RandomAccessIter right = last;
    
    while (std::distance(left, right) > 0) {
        RandomAccessIter middle = left + std::distance(left, right) / 2;
        if (*middle <= target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int main() {
    std::vector<int> s{1, 1, 1, 1, 1, 2, 2, 2, 2, 5, 5, 5, 5};
    auto iter = std::upper_bound(s.begin(), s.end(), 5);
    auto iter_2 = UpperBound(s.begin(), s.end(), 5);
    std::cout << (iter == iter_2) << "\n";
}
