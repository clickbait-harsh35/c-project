
# Node Watcher in C++

A simple multi-threaded node watcher that pings a list of IP addresses or domains and logs their status.

## Features
- ICMP Ping-based status checking
- Multi-threaded
- Configurable via `config.txt`

## How to Use

1. Add IPs/domains to `config.txt`
2. Build the project:
   ```bash
   g++ -std=c++17 main.cpp NodeWatcher.cpp -o node-watcher -pthread
   ```
3. Run:
   ```bash
   ./node-watcher
   ```

## Notes
- Works on Linux/macOS (uses `ping -c 1`)
- Windows users may need to change the ping command format in `NodeWatcher.cpp`
