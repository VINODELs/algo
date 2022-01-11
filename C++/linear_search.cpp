#include <iostream>
#include <vector>

template <typename ForwardIterator, typename ValueType>
ForwardIterator LinearSearch(ForwardIterator first, ForwardIterator last, const ValueType& target) {
    ForwardIterator iter = first;
    while (iter != last) {
        if (*iter == target) {
            return iter;
        }
        ++iter;
    }
    return last;
}

int main() {
    std::vector<int> s{1, 2, -1, 23, -31, 12, 22};
    std::cout << (LinearSearch(s.begin(), s.end(), 2) == s.begin() + 1) << "\n";
    std::cout << (LinearSearch(s.begin(), s.end(), 24) == s.end()) << "\n";
    return 0;
}
