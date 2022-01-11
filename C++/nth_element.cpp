#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int RANDOM_SEED = 13337;
std::mt19937 gen(RANDOM_SEED);

template <typename RandomAccessIter>
RandomAccessIter GetPivot(RandomAccessIter first, RandomAccessIter last) {
    std::uniform_int_distribution<int> dist(0, std::distance(first, last) - 1);
    return first + dist(gen);
}

template <typename RandomAccessIter>
RandomAccessIter Partition(RandomAccessIter first, RandomAccessIter last, RandomAccessIter pivot) {
    RandomAccessIter copy_pivot = pivot;
    std::swap(*pivot,*(last - 1));
    RandomAccessIter left = first;
    RandomAccessIter right = last;

    while (right != last) {
        if (*right < *copy_pivot) {
            std::swap(*left, *right);
            ++left;
        } else {
            if (!(right == last - 1)) {
                std::swap(*left, *right);
                ++left;
            }
        }
        ++right;
    }
    std::swap(*(last - 1), *left);
    return left;
}

template <typename RandomAccessIter>
RandomAccessIter NthElement(RandomAccessIter first, RandomAccessIter last, RandomAccessIter nth) {
    RandomAccessIter left = first;
    RandomAccessIter right = last;
    RandomAccessIter nth_iter = nth;
    while (std::distance(left, right) > 0) {
        RandomAccessIter pivot = GetPivot(left, right);
        RandomAccessIter possible_nth = Partition(left, right, pivot);

        if (possible_nth == nth) {
            return possible_nth;
        } else if (possible_nth > nth) {
            right = possible_nth;
        } else { 
            left = possible_nth + 1;
        }
    }
    return left;
}

int main() {
    std::vector<int> s{1, 5, 2, 6, 8, 3, 7};
    std::cout << (NthElement(s.begin(), s.end(), s.begin() + 5) == s.begin() + 3) << "\n";
    return 0;
}
