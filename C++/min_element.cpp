#include <algorithm>
#include <iostream>
#include <vector>

template <typename ForwardIterator>
ForwardIterator MinElement(ForwardIterator first, ForwardIterator last) {
    ForwardIterator cur_min = first;
    
    for (ForwardIterator iter = first; iter != last; ++iter) {
        if (*iter < *cur_min) {
            cur_min = iter;
        }
    }
    return cur_min;
}

int main() {
    std::vector<int> s{1, 2, 3, 4, -2, 34, 112, 232, -1};
    std::cout << (MinElement(s.begin(), s.end()) == std::min_element(s.begin(), s.end())) << "\n";
    return 0;
}
