#include "../src/module_a.c"
#include "libmoduleb_mock.h"
#include <gtest/gtest.h>
#include "gmock/gmock.h"

using ::testing::_;

// create unit testing class for module A from TestFixture
class ModuleAUnitTest : public TestFixture{
public:
    ModuleAUnitTest(){
        // here you can put some initializations
    }
};


TEST_F(ModuleAUnitTest, findPrimeCounts) 
{
    int interval = 20;

    // module_b_func will be called to check if 0, 1, ... 20 are primes
    // Hence, the func should be invoked 21 times to be precise
    EXPECT_CALL(*_libBmockPtr, module_b_func(_)).Times(interval+1);
    module_a_func(interval);
}

TEST_F(ModuleAUnitTest, findPrimeCountWithFake) 
{

    // Replace mock with fake functions
    (*_libBmockPtr).delegateToFake();

    /* 900 prime numbers between [0,7000] */
    int result = module_a_func(7000);
    EXPECT_EQ(900, result);

    /* Mock LUT supports first 1000 primes only */
    result = module_a_func(10000);
    EXPECT_EQ(-1, result);

}
 
int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

