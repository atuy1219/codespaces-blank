#pragma once

#include "MagicInfo.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace magicmaker {

class MagicInfoPersistence final {
public:
    MagicInfoPersistence() = delete;

    static void save(std::int32_t slot, const MagicInfo& info);
    static MagicInfo load(std::int32_t slot);

private:
    static std::string formatSlotKey(const char* format, std::int32_t slot);
    static std::string plistPath(const std::string& baseName);
    static void saveIntList(const std::vector<std::int32_t>& values, const std::string& baseName);
    static void saveVec2List(const std::vector<ax::Vec2>& values, const std::string& baseName);
    static std::vector<std::int32_t> loadIntList(const std::string& baseName);
    static std::vector<ax::Vec2> loadVec2List(const std::string& baseName);
};

}  // namespace magicmaker
