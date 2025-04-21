
#pragma once
#include <string>
#include <vector>

class NodeWatcher {
public:
    explicit NodeWatcher(const std::string& configPath);
    void loadNodes();
    void startMonitoring();

private:
    std::string configPath;
    std::vector<std::string> nodes;
    bool pingNode(const std::string& ip);
};
