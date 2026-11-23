#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class ProductOfNumbers {
private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix = {1};
    }

    void add(int num) {
        if (num == 0) {
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int validCount = static_cast<int>(prefix.size()) - 1;
        if (k > validCount) {
            return 0;
        }
        return prefix.back() / prefix[validCount - k];
    }
};

int main() {
    ProductOfNumbers stream;
    stream.add(3); // [3]
    stream.add(0); // [3, 0]
    stream.add(2); // [3, 0, 2]
    stream.add(5); // [3, 0, 2, 5]
    stream.add(4); // [3, 0, 2, 5, 4]

    cout << "getProduct(2): " << stream.getProduct(2) << endl;
    cout << "getProduct(3): " << stream.getProduct(3) << endl;
    cout << "getProduct(4): " << stream.getProduct(4) << endl;

    stream.add(8); // [3, 0, 2, 5, 4, 8]
    cout << "getProduct(2): " << stream.getProduct(2) << " | Expected: 32\n";

    return 0;
}
