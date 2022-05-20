#include <iostream>
#include <fstream>
#include <algorithm>

bool happens(int a, int b, int c, int d) {
    if (a == c && b == d) {
        return true;
    }
    while (b != 0) {
        if (b > a) {
            std::swap(a, b);
            if (a == c && b == d) {
                return true;
            }
        }
        a -= b;
        if (a == c && b == d) {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    std::ifstream Value("input.txt");
    Value >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c, d;
        Value >> a >> b >> c >> d;
        if (happens(a, b, c, d)) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    
    Value.close();
}
