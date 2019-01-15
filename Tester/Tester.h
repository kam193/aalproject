#ifndef AAL_TESTER_H
#define AAL_TESTER_H

#include <chrono>

class Tester{
    struct TestCase
    {
        int size;
        long long int time;
    };
    TestCase make_test(int size, int attempts);

    public:
        void run_tests(int start_size, int step_size, int steps, int attempts);

};

#endif