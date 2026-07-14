#pragma once

#include "axmol.h"

#include <cstddef>
#include <string>
#include <vector>

class MainScene final : public ax::Scene {
public:
    bool init() override;

private:
    void loadCurrentCsb();
    void cycleCsb(int direction);
    void runPersistenceTest();
    void updateStatus(const std::string& message);
    void installInput();

    ax::Node* _csbRoot = nullptr;
    ax::Label* _statusLabel = nullptr;
    std::size_t _csbIndex = 0;
    std::vector<std::string> _csbFiles;
};
