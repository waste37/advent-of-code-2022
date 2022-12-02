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
                    case 'X': // lose
                        myresult += 0 + 3;
                        break; 
                    case 'Y': // draw 
                        myresult += 3 + 1;
                        break;
                    case 'Z': // win
                        myresult += 6 + 2;
                        break;
                }
                break;
            case 'B': // paper
                switch (me) {
                    case 'X': // lose
                        myresult += 0 + 1;
                        break; 
                    case 'Y': // draw 
                        myresult += 3 + 2;
                        break;
                    case 'Z': // win
                        myresult += 6 + 3;
                        break;
                }
                break;
            case 'C': // scissor
                switch (me) {
                    case 'X': // lose
                        myresult += 0 + 2;
                        break; 
                    case 'Y': // draw 
                        myresult += 3 + 3;
                        break;
                    case 'Z': // win
                        myresult += 6 + 1;
                        break;
                }
                break;
        }
    } 
    std::cout << myresult << std::endl;
    return 0;
}
