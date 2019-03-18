#include "testsuite.h"

TestSuite::TestSuite()
{
    suite().push_back(this);
}


std::vector<TestSuite*> & TestSuite::suite()
{
    static std::vector<TestSuite*> objects;
    return objects;
}
