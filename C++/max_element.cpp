#include <algorithm>
#include <iostream>
#include <vector>

template <typename ForwardIterator>
ForwardIterator MaxElement(ForwardIterator first, ForwardIterator last) {
    ForwardIterator cur_max = first;
    
    for (ForwardIterator iter = first; iter != last; ++iter) {
        if (*iter > *cur_max) {
            cur_max = iter;
        }
    }
    return cur_max;
}

int main() {
    std::vector<int> s{1, 2, 3, 4, -2, 34, 112, 232, -1};
    std::cout << (MaxElement(s.begin(), s.end()) == std::max_element(s.begin(), s.end())) << "\n";
    return 0;
}
