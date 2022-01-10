#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void PrintVector(const std::vector<T>& array) {
    for (const T& value : array) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

// Template heapsort

/* Arguments:
    1) first - iterator refering to the first element of a container, from which to 
    perform sorting

    2) last - iterator pointing to a memory segment directly after the last container
    element up to which to perform sorting
    
    3) comp - function for elements comparison, optional for common data types
*/

template <typename RandomAccessIterator, 
    typename Compare=std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
void Heapify(RandomAccessIterator first, RandomAccessIterator last, 
        RandomAccessIterator node, Compare comp=Compare()) {
    if (2 * std::distance(first, node) + 2 <= std::distance(first, last)) {
        RandomAccessIterator largest = node;
        RandomAccessIterator left = first + 2 * std::distance(first, node) + 1;
        RandomAccessIterator right = first + 2 * std::distance(first, node) + 2;
        
        if (left < last && !(comp(*left, *largest))) {
            largest = left;
        }
        if (right < last && !(comp(*right, *largest))) {
            largest = right;
        }
        if (largest != node) {
            std::swap(*node, *largest);
            Heapify(first, last, largest, comp);
        }
    }
    return;
}

// works in O(NlogN),
// TODO: make for O(N) 
template<typename RandomAccessIterator, 
    typename Compare=std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
void MakeHeap(RandomAccessIterator first, RandomAccessIterator last, Compare comp=Compare()) {
    if (last - first < 2) {
        return;
    }
    for (RandomAccessIterator iter = first + ((last - first) / 2) - 1; (iter + 1) != first; --iter) {
        Heapify(first, last, iter, comp);
    }
}

// Complexity: TL - O(NlogN), ML - O(1)
// Features: inplace sort, unstable
template <typename RandomAccessIterator, 
    typename Compare=std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>>
void HeapSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp=Compare()) {
    if (last - first < 2) {
        return;
    }
    MakeHeap(first, last, comp);
    for (RandomAccessIterator iter = last - 1; iter != first; --iter) {
        std::swap(*first, *iter);
        --last;
        Heapify(first, last, first, comp);
    }
}

int main() {
    std::vector<int> array{32, 123, 1231, -12312, 123, 1231212, 112, 1, 2, 45, -31};
    HeapSort(array.begin(), array.end());
    PrintVector(array);
    return 0;
}
