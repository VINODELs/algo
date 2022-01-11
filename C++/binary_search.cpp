#include <iostream>
#include <vector>

bool bin_search(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    
    while (right - left > 0) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> s{2, 53, 3131, 12414, 1111111, 28124124};
    int target_one = 53;
    int target_two = 12415;
    std::cout << bin_search(s, target_one) << " " << bin_search(s, target_two) << "\n";
    return 0;
}
