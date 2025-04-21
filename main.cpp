
#include "NodeWatcher.h"

int main() {
    NodeWatcher watcher("config.txt");
    watcher.loadNodes();
    watcher.startMonitoring();
    return 0;
}
