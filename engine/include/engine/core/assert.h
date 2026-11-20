#pragma once

#include "log.h"

#ifndef NDEBUG
    #define BK_ASSERT(x, ...) if (!(x)) { BK_LOG_ERROR("Assertion failed: {}", __VA_ARGS__); std::raise(SIGTRAP); }
    #define BK_CORE_ASSERT(x, ...) if (!(x)) { BK_LOG_CORE_ERROR("Assertion failed: {}", __VA_ARGS__); std::raise(SIGTRAP); }
#else
    #define BK_ASSERT(x, ...)
    #define BK_CORE_ASSERT(x, ...)
#endif