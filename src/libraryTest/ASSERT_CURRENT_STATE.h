#pragma once

#include "Scanner.h"
#include <memory>

// TODO create a custom matcher for this instead!
template <typename T> static void ASSERT_CURRENT_STATE(std::shared_ptr<Scanner> scanner)
{
    ASSERT_TRUE(dynamic_cast<std::shared_ptr<T>>(scanner->CurrentState()) != NULL);
}
