#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class LogData {
    string serviceName, logType, timestamp;

public:
    LogData(const string& serviceName, const string& logType, const string& timestamp)
        : serviceName(serviceName), logType(logType), timestamp(timestamp) {}

    string getServiceName() const { return serviceName; }
    string getLogType() const { return logType; }
    string getTimestamp() const { return timestamp; }
};

class LogManager {
    map<string, LogData> logs;

public:
    void addLog(const string& serviceName, const string& logType, const string& timestamp) {
        logs[serviceName] = LogData(serviceName, logType, timestamp);
    }

    vector<LogData> consolidateLogs() {
        vector<LogData> logVector;
        for (const auto& pair : logs) {
            logVector.push_back(pair.second);
        }
        sort(logVector.begin(), logVector.end(),
             [](const LogData& a, const LogData& b) {
                 return a.getTimestamp() > b.getTimestamp();
             });
        return logVector;
    }

    void printLogs() {
        vector<LogData> logVector = consolidateLogs();
        for (const LogData& log : logVector) {
            cout << log.getServiceName() << ": " << log.getLogType() << ", " << log.getTimestamp() << endl;
        }
    }
};

int main() {
    LogManager logManager;
    logManager.addLog("micro-service-a1", "INFO", "2023-07-24 12:30:00");
    logManager.addLog("micro-service-c1", "ERROR", "2023-07-24 12:40:00");
    // Add more logs here...

    logManager.printLogs();

    return 0;
}
