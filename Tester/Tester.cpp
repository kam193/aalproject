#include <cmath>

#include "Tester.h"
#include "../Generator/Generator.h"
#include "../Solver/Solver.h"

using namespace std;

long double theoretic(long long int size){
    return pow(32.0, size*size) * log2(size*size);
}

Tester::TestCase Tester::make_test(int size, int attempts){
    TestCase test = {size, 0};
    Generator generator(size, size);

    for (int i = 0; i < attempts; ++i){
        Grid grid = generator.generate();
        Solver solver(grid);
        
        chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        solver.solve();
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        test.time += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    test.time /= attempts;

    return test;
}

void Tester::run_tests(int start_size, int step_size, int steps, int attepts)
{
    vector<TestCase> tests;
    int size = start_size;
    for (int i = 0; i < steps; ++i)
    {
        tests.push_back(make_test(size, attepts));
        size += step_size;
    }

    long long int median;
    long long int median_time;
    if (steps % 2 == 1)
    {
        median = tests[steps/2].size;
        median_time = tests[steps/2].time;
    }
    else
    {
        median = (tests[steps/2].size + tests[steps/2 + 1].size) / 2;
        median_time = (tests[steps/2].time + tests[steps/2 + 1].time) / 2;
    }

    long double theoretic_median = theoretic(median);

    cout << "  N (NxN) |    microseconds    | q(n) " << endl;
    cout << "------------------------------------" << endl;
    for (auto &test : tests)
    {
        cout.width(10);
        cout << test.size << "|";
        cout.width(20);
        cout << test.time << "| ";
        cout << (test.time * theoretic_median) / (theoretic(test.size) * median_time) << endl;
    }
}