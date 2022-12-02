#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

int main ()
{
    std::ifstream f("input");   
    if (!f.is_open ()) {
        return -1;
    }

    std::string line;
    std::vector<long long> v;
    long long tmp, max1, max2, max3;
    max1 = max2 = max3 = -1;

    long long acc = 0;
    while (std::getline (f, line)) {
        std::cout << "max1 = " << max1
            << ", max2 = " << max2
            << ", max3 = " << max3 << std::endl;

        if (line.size() == 0) {
            v.clear ();
            if (acc > max1) {
                max3 = max2;
                max2 = max1;
                max1 = acc;
            } else if (acc > max2) {
                max3 = max2;
                max2 = acc;
            } else if (acc > max3) {
                max3 = acc;
            }

            acc = 0;
        } else {
            std::istringstream ss(line);
            ss >> tmp;
            acc += tmp;
        }
    }

    std::cout << "result is " << max1 + max2 + max3 << std::endl;

    return 0;
}
