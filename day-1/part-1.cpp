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
    long long tmp, max = -1;

    long long acc = 0;
    while (std::getline (f, line)) {
        if (line.size() == 0) {
            std::cout << " elf had " << acc <<" calories\n";
            v.clear ();
            if (acc > max) {
                max = acc;
            }
            acc = 0;
        } else {
            std::cout << " reading elf\n";
            std::istringstream ss(line);
            ss >> tmp;
            acc += tmp;
        }
    }

    std::cout << "the elf with most calories has " << max << std::endl;

    return 0;
}
