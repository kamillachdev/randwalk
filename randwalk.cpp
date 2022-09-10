#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;

    ofstream file;
    file.open("text.txt");

    srand(time(0));

    Vector step;
    Vector result(0.0, 0.0);

    double direction;
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "Enter the distance to go(k to end): ";
    while (cin >> target)
    {
        cout << "Enter length of the step: ";
        if (!(cin >> dstep))
            break;
        
        file << "Distance to go: " << target << ", lenght of step: " << dstep << "\n";
        file << "0: (x,y) = (0, 0)\n";
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            file << steps << ": " << result << "\n";
        }

        //display in the program
        cout << "After " << steps << " steps a man reached the distance: \n";
        cout << result << endl;

        result.polar_mode();
        cout << "or" << endl << result << endl;


        cout << "Average length of the apparent step: " << result.magval() / steps << endl;

        result.rect_mode();

        //display in the file
        file << "After " << steps << " a man reached the distance: \n";
        file << result << endl;

        result.polar_mode();
        file << "or" << endl << result << endl;

        file << "Average length of the apparent step: " << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter the distance to go(k to end): ";
    }
    cout << "Finish!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    file.close();
    return 0;
}