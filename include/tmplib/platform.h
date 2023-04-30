#pragma once

// clang-format off

#if defined(CPP_LIB_EXPORT)
#   if defined(_MSC_VER)
#       define LIB_EXPORT_API __declspec(dllexport)
#   else // gnu
#       define LIB_EXPORT_API __attribute((visibility("default")))
#   endif
#else
#   define LIB_EXPORT_API // empty define
#endif

// clang-format on
