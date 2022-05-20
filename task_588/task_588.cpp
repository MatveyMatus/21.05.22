#include <iostream>
#include <fstream>
#include <vector>

void solvesSlow(int b) {
    long long range = 1;
    for (int i = 0; i < b; ++i) {
        range *= b;
    }
    std::vector<int> Array(b);
    std::vector<int> ArraySize(b);
    for (long long code = 0; code < range; ++code) {
        long long t = code;
        for (int i = 0; i < b; ++i) {
            Array.at(i) = int(t % b);
            t /= b;
        }
        for (int &q : ArraySize) {
            q = 0;

        }
        for (int j : Array) {
            ArraySize.at(j)++;
        }
        if (Array == ArraySize) {
            std::cout << "b= " << b << std::endl;
            for (int j : Array) {
                std::cout << j << std::endl;
            }
        }
    }
}

void research() {
    for (int b = 2; b <= 10; ++b) {
        solvesSlow(b);
    }
}

int main()
{
    //research();
    int b;

    std::ifstream Value("input.txt");
    Value >> b;
    Value.close();

    std::ofstream result("output.txt");
    if (b == 2 || b == 3 || b == 6) {
        result << -1;
    }
    else if (b == 4) {
        result << "2\n1\n0\n1";
    }
    else if(b==5) {
        result << "1\n2\n0\n0\n2";
    }
    else {
        result << "2\n1\n";
        for (int i = 0; i < b - 7; ++i) {
            result << "0\n";
        }
        result << "1\n0\n0\n0\n" << b - 4;
    }
    result.close();

    return 0;
}

