#include <iostream>
#include <random>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <forward_list>
#include <unordered_set>
#include <bitset>

using std::forward_list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unordered_set;

void runTests(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}

using namespace std;

#include "Multithreading/Multithreading Test/producer_consumer.h"
#include "cracking_code_interview/8.9.Parens/8.9.Parens.h"

int main(int argc, char* argv[])
{
/*    jr::ProducerConsumerTest m;
    m.producedConsumerTest();*/
/*    vector<string> testParens = possibleParens(3);
    for(string pos : testParens) {
        cout << pos << ", ";
    }*/
   runTests(argc, argv);
}