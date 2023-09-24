#include "gmock/gmock.h"

#include "Persistence.h"
#include "PersistenceTest.h"
#include "KeyedMemoryPersistence.h"
#include "TestSerializable.h"

using namespace testing;

class KeyedMemoryPersistenceTest: public Test
{
public:
    static Persistence<TestSerializable>* CreatePersistence()
    {
        return new KeyedMemoryPersistence<TestSerializable>("table");
    }
};

INSTANTIATE_TEST_CASE_P(KeyedMemory, PersistenceTest, Values(&KeyedMemoryPersistenceTest::CreatePersistence));

TEST_F(KeyedMemoryPersistenceTest, IsPersistent) // note TEST_F, not TEST_P 
{
    TestSerializable object("A", "1");

    KeyedMemoryPersistence<TestSerializable> firstPersister("");
    firstPersister.Add(object);

    KeyedMemoryPersistence<TestSerializable> secondPersister("");
    auto retrieved = std::make_unique<TestSerializable>(secondPersister.Get("1"));

    ASSERT_THAT(*retrieved, Eq(object));
};
