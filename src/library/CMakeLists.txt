cmake_minimum_required(VERSION 3.20.0)

set(target_name "library")

include_directories(include $ENV{BOOST_ROOT}/include)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
    Book.cpp
    Branch.cpp
    BranchAccess.cpp
    BranchService.cpp
    Catalog.cpp
    ClassificationService.cpp
    Endpoint.cpp
    EndpointValidator.cpp
    Holding.cpp
    HoldingService.cpp
    InventoryReport.cpp
    MailDestination.cpp
    MailMessage.cpp
    Patron.cpp
    PatronAccess.cpp
    PatronService.cpp
    Scanner.cpp
    ScannerState.cpp
    ScannerStateCheckin.cpp
    ScannerStateCheckout.cpp
    ScannerStateInventory.cpp
    ScannerStateWaiting.cpp
    StreamLineReader.cpp
    TimestampSource.cpp
    Transport.cpp)

add_library(${target_name} ${sources})
target_link_libraries(${target_name} pthread)
target_link_libraries(${target_name} rt)

target_compile_features(${target_name} PUBLIC cxx_std_17)
