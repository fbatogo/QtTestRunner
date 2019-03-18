#include "runtestsuites.h"

#include <iostream>

#include "testsuite.h"
#include <QtTest>

RunTestSuites::RunTestSuites()
{
    mArgc = 0;
    mArgv = nullptr;

    // Populate the parameter map.
    populateParameterMap();
}

/**
 * @brief RunTestSuites::setCommandLineParameters - Provide the command line parameters that should be used for
 *      running this test app.
 *
 * @param argc - The number of arguments that were passed in.
 * @param argv - A pointer to an array of arguments that are provided.
 *
 * @return true if the command line parameters are all understood.  false otherwise.
 */
bool RunTestSuites::setCommandLineParameters(int argc, char *argv[])
{

}

/**
 * @brief RunTestSuites::knownParameters - Return the parameters that can be used with this test suite runner.
 *
 * @return QMap<QString, QMap<QString, QString> > containing the map of parameters that can be used with this
 *      test suite runner.
 */
QMap<QString, QMap<QString, QString> > RunTestSuites::knownParameters()
{
    return mParameterMap;
}

/**
 * @brief RunTestSuites::parameterHelp - Return a string that indicates the parameters that are understood by this
 *      test helper app, and what each one does.
 *
 * @return QString containing the list of parameters that are understood and supported.
 */
QString RunTestSuites::parameterHelp()
{
    QString result;

    result = mArgv[0];
    result += " - Missing Qt Unit Test Runner\n\n";
    result += "  Command Line Options :\n\n";
    result += "Logging Options\n";
    result += "---------------\n";
    result += " -o <filename_prefix> -- Causes test output to be written using the specified prefix to the result files.\n";
    result += " -txt -- Output the test results as a text file.\n";
    result += " -xml -- Output the test results as an XML file.\n";
    result += " -xunitxml -- Output the test results as an Xunit XML file.\n";
    result += "\n\n";
    result += "Test Log Detail Options\n";
    result += "-----------------------\n";
    result += " -silent -- Only show fatal errors in the output test logs.\n";
    result += " -v1 -- Show each test function as it is entered.\n";
    result += " -v2 -- Show each QCOMPARE() and QVERIFY().\n";
    result += " -vs -- Show all signals that get emitted and slot invocations resulting from thos signals.\n";
    result += "\n\n";
    result += "Testing Options\n";
    result += "---------------\n";
    result += " -functions -- List all available test functions.\n";
    result += " -datatags -- List all data tags available in a test.\n";
    result += "\n\n";

    return result;
}

bool RunTestSuites::parametersAreValid()
{

}

/**
 * @brief RunTestSuites::executeAll - Execute all of the tests that are currently queued up to run.
 *
 * @return int containing the number of tests that failed.
 */
int RunTestSuites::executeAll()
{
    // setup lambda
    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    auto &suite = TestSuite::suite();
    for (auto it = suite.begin(); it != suite.end(); ++it) {
        std::cout << "Class name : " << (*it)->metaObject()->className() << std::endl;
        runTest(*it);
    }
}

int RunTestSuites::executeByPattern(QString pattern)
{

}

/**
 * @brief RunTestSuites::populateParameterMap - Populate the map of parameters and parameter headings that
 *      are used for this app.
 */
void RunTestSuites::populateParameterMap()
{

}
