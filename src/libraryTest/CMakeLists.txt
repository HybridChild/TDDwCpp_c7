cmake_minimum_required(VERSION 3.20.0)

set(target_name "test")

include_directories($ENV{GTEST_HOME}/googlemock/include $ENV{GTEST_HOME}/googletest/include $ENV{BOOST_ROOT}/include)
link_directories($ENV{GTEST_HOME}/out/build/lib ../library/build)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
    main.cpp 
    BarcodeUtilTest.cpp
    BookTest.cpp
    BranchAccessTest.cpp
    BranchServiceTest.cpp
    BranchTest.cpp
    CatalogTest.cpp
    ClassificationServiceTest.cpp
    HoldingBarcodeTest.cpp
    HoldingServiceTest.cpp
    HoldingTest.cpp
    InventoryReportTest.cpp
    KeyedFilePersistenceTest.cpp
    KeyedMemoryPersistenceTest.cpp
    PatronAccessTest.cpp
    PatronServiceTest.cpp
    PatronTest.cpp
    PersistenceTest.cpp
    ReportMailerTest.cpp
    ScannerStateCheckinTest.cpp
    ScannerStateCheckoutTest.cpp
    ScannerStateInventoryTest.cpp
    ScannerStateWaitingTest.cpp
    ScannerTestData.cpp
    StreamLineReaderTest.cpp
    TimestampSourceTest.cpp
    VectorReaderTest.cpp)

add_executable(${target_name} ${sources})

target_link_libraries(${target_name} pthread)
target_link_libraries(${target_name} gmock)
target_link_libraries(${target_name} gtest)
target_link_libraries(${target_name} rt)
target_link_libraries(${target_name} library)

target_compile_features(${target_name} PUBLIC cxx_std_17)
