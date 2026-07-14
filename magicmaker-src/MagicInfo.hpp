#pragma once

#include "axmol.h"

#include <cstdint>
#include <string>
#include <vector>

namespace magicmaker {

struct MagicInfo {
    std::int32_t type = 9;
    float angle = 0.0F;
    std::int32_t power = 1;
    float size = 0.0F;

    std::vector<ax::Vec2> locus;
    std::string name;
    std::vector<std::int32_t> mahoujin;

    float mp = 0.0F;
    float eishoTime = 0.8F;
    float speed = 0.8F;
    bool isNear = false;
    float fukitobasiDir = 0.0F;
    float jizokuTime = 1.5F;
    std::int32_t unknown44 = 0;
    float baSize = 2.5F;
    float baTime = 0.5F;
    std::int32_t baNum = 1;
    float baSizeAll = 0.0F;
};

}  // namespace magicmaker
