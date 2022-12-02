#include <iostream>
#include <fstream>
#include <string>

int main () 
{
    std::ifstream i("input");

    if (!i.is_open ()) {
        return -1;
    }

    char me, opponent;
    long long myresult = 0;
    while (i >> opponent >> me) {
        switch (opponent) {
            case 'A': // rock
                switch (me) {
                    case 'X': // rock
                        myresult += 3 + 1;
                        break; 
                    case 'Y': // paper 
                        myresult += 6 + 2;
                        break;
                    case 'Z': // scissors
                        myresult += 0 + 3;
                        break;
                }
                break;
            case 'B': // paper
                switch (me) {
                    case 'X': // rock
                        myresult += 0 + 1;
                        break;
                    case 'Y': // paper
                        myresult += 3 + 2;
                        break;
                    case 'Z': // scissors
                        myresult += 6 + 3;
                        break;
                }
                break;
            case 'C': // scissor
                switch (me) {
                    case 'X': // rock
                        myresult += 6 + 1;
                        break;
                    case 'Y': // paper
                        myresult += 0 + 2;
                        break;
                    case 'Z': // scissors
                        myresult += 3 + 3;
                        break;
                }
                break;
        }
    } 
    std::cout << myresult << std::endl;
    return 0;
}
