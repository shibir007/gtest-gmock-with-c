// MOCKING C-Functions with GMOCK :)
#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "libmoduleb_fake.h"

using namespace ::testing;
using ::testing::Return;
using ::testing::Invoke;

class LibBMock {
public:
   virtual ~LibBMock() {}
   MOCK_METHOD1(module_b_func, int(int));

   void delegateToFake() {
       ON_CALL(*this, module_b_func(_)).WillByDefault(testing::Invoke(
           [this] (int n) {
               return fakeLibB_.module_b_func_get_from_LUT(n);
           }
       ));
   }

private:
  FakeLibB fakeLibB_; 
};

class TestFixture: public ::testing::Test{
public:
    TestFixture(){
        _libBmockPtr.reset(new ::testing::NiceMock<LibBMock>());
    }
    ~TestFixture(){
        _libBmockPtr.reset();
    }
    virtual void SetUp(){}
    virtual void TearDown(){}

    // pointer for accessing mocked library
    static std::unique_ptr<LibBMock> _libBmockPtr;
};

// instantiate mocked lib
std::unique_ptr<LibBMock> TestFixture::_libBmockPtr;

// fake lib functions
int  module_b_func(int val){return TestFixture::_libBmockPtr->module_b_func(val);}
