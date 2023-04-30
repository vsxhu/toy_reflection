#pragma once
#include "platform.h"

namespace tmp
{
class LIB_EXPORT_API TmpLib
{
   public:
    TmpLib() = default;
    ~TmpLib() = default;
    static void Run();
};
}  // namespace tmp
