#include <iostream>
#include <vector>

template<typename T>
void PrintVector(const std::vector<T>& array) {
    for (const T& value : array) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

template <typename RandomAccessIter, 
         typename Compare=std::less<typename std::iterator_traits<RandomAccessIter>::value_type>>
void SelectionSort(RandomAccessIter first, RandomAccessIter last, Compare comp=Compare()) {
    RandomAccessIter start = first;
    while (start + 1 != last) {
        RandomAccessIter cur_min = start + 1;
        for (RandomAccessIter inner = start + 1; inner < last; ++inner) {
            if (comp(*inner, *cur_min)) {
                cur_min = inner;
            }
        }
        std::swap(*start, *cur_min);
        ++start;
    }
}

int main() {
    std::vector<int> array{24, -12, 123, -123, 12, 14, 54, -31, 1, 4, 2, 1022, 33};
    SelectionSort(array.begin(), array.end());
    PrintVector(array);
    return 0;
}
