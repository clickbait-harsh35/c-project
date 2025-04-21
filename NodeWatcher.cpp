
#include "NodeWatcher.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex outputMutex;

NodeWatcher::NodeWatcher(const std::string& configPath) : configPath(configPath) {}

void NodeWatcher::loadNodes() {
    std::ifstream file(configPath);
    std::string ip;
    while (std::getline(file, ip)) {
        if (!ip.empty()) {
            nodes.push_back(ip);
        }
    }
}

bool NodeWatcher::pingNode(const std::string& ip) {
    std::string command = "ping -c 1 -W 1 " + ip + " > /dev/null 2>&1";
    return (system(command.c_str()) == 0);
}

void NodeWatcher::startMonitoring() {
    std::vector<std::thread> threads;
    for (const auto& ip : nodes) {
        threads.emplace_back([ip]() {
            while (true) {
                bool online = NodeWatcher("").pingNode(ip);
                std::lock_guard<std::mutex> lock(outputMutex);
                std::cout << "[" << ip << "] is " << (online ? "ONLINE" : "OFFLINE") << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
        });
    }

    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }
}
