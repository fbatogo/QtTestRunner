#ifndef TESTSUITE_H
#define TESTSUITE_H

// The original idea and code for this came from https://alexhuszagh.github.io/2016/using-qttest-effectively/ it may have
// been modified to work the way we need it to.  (Or, it may not have been!)

#include <QObject>
#include <vector>

class TestSuite: public QObject
{
public:
     TestSuite();

     static std::vector<TestSuite*> & suite();
};

#endif // TESTSUITE_H
