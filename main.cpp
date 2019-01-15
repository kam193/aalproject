#include <iostream>
#include <vector>
#include <getopt.h>

#include "DataStructure/Grid.h"
#include "Solver/Solver.h"
#include "Solver/BrutSolver.h"
#include "Generator/Generator.h"
#include "Tester/Tester.h"

using namespace std;

int main(int argc, char **argv)
{
    int m = -1;
    int start_size = -1;
    int number_of_steps = -1;
    int step = -1;
    int rand_count = -1;
    opterr = 0;
    int c;
    while ((c = getopt(argc, argv, "hm:n:k:s:r:")) != -1)
        switch (c)
        {
        case 'm':
            m = atoi(optarg);
            break;
        case 'n':
            start_size = atoi(optarg);
            break;
        case 'k':
            number_of_steps = atoi(optarg);
            break;
        case 's':
            step = atoi(optarg);
            break;
        case 'r':
            rand_count = atoi(optarg);
            break;
        case 'h':
            cout << "-m1 : Solve from stdin\n"
                    "-m2 : Generate grid \n"
                    "\t -n <size> : Size NxN of grid\n"
                    "-m3 : Run tester\n"
                    "\t -n <size> : Start size NxN grid\n"
                    "\t -k <int> : Number of steps\n"
                    "\t -s <int> : Size of step\n"
                    "\t -r <int> : Number of attempts in every step\n";
            return 0;
        case '?':
            fprintf(stderr, "Options %d requires an argument or unknown.\n", optopt);
            return 1;
        default:
            return 1;
        }

    if (m == 1){
        Grid grid;
        cin >> grid;
        Solver solver(grid);
        cout << solver.solve();
    }
    else if (m == 2){
        if (start_size == -1)
        {
            cout << "-n is required!\n";
            return 1;
        }
        Generator generator(start_size, start_size);
        cout << generator.generate();
    }
    else if (m == 3){
        if (start_size == -1 || number_of_steps == -1 || step == -1 || rand_count == -1)
        {
            cout << "-n -k -s -r are required!\n";
            return 1;
        }
        Tester tester;
        tester.run_tests(start_size, step, number_of_steps, rand_count);
    }
    else{
        cout << "Only -m1, -m2, -m3 are supported!\n";
        return 1;
    }

    return 0;
}