
#include <iostream>

using namespace std;

class MultiplyBy {
private:
    int factor;

public:
    MultiplyBy(int x) : factor(x) {
    }

    int operator () (int other) const {
        return factor * other;
    }
};