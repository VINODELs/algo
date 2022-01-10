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

template <typename Iterator, typename Compare=std::less<typename std::iterator_traits<Iterator>::value_type>>
void Heapify (Iterator first, Iterator last, Iterator node, Compare comp=Compare()) {
    if (2 * std::distance(first, node) + 2 <= std::distance(first, last)) {
        Iterator largest = node;
        Iterator left = first + 2 * std::distance(first, node) + 1;
        Iterator right = first + 2 * std::distance(first, node) + 2;
        
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
template<typename Iterator, typename Compare=std::less<typename std::iterator_traits<Iterator>::value_type>>
void MakeHeap(Iterator first, Iterator last, Compare comp=Compare()) {
    if (last - first < 2) {
        return;
    }
    for (Iterator iter = first + ((last - first) / 2) - 1; (iter + 1) != first; --iter) {
        Heapify(first, last, iter, comp);
    }
}

// Complexity: TL - O(NlogN), ML - O(1)
// Features: inplace sort, unstable
template <typename Iterator, typename Compare=std::less<typename std::iterator_traits<Iterator>::value_type>>
void HeapSort(Iterator first, Iterator last, Compare comp=Compare()) {
    if (last - first < 2) {
        return;
    }
    MakeHeap(first, last, comp);
    for (Iterator iter = last - 1; iter != first; --iter) {
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
