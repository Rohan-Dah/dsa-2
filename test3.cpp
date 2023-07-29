#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class LogData {
public:
    std::string logType;
    std::string timestamp;

    LogData() {}
    LogData(const std::string& logType, const std::string& timestamp) : logType(logType), timestamp(timestamp) {}
};

class LogEntry {
private:
    std::unordered_map<std::string, LogData> logs;

public:
    void addLog(const std::string& serviceName, const LogData& logData) {
        if (logs.find(serviceName) == logs.end() || logData.timestamp > logs[serviceName].timestamp) {
            logs[serviceName] = logData;
        }
    }

    const std::unordered_map<std::string, LogData>& getLogs() const {
        return logs;
    }
};

class LogConsolidator {
private:
    std::vector<LogEntry> logEntries;

public:
    void addLogEntry(const LogEntry& logEntry) {
        logEntries.push_back(logEntry);
    }

    std::unordered_map<std::string, LogData> consolidateLogs() {
        std::unordered_map<std::string, LogData> consolidatedLogs;

        for (const auto& logEntry : logEntries) {
            const std::unordered_map<std::string, LogData>& logs = logEntry.getLogs();
            for (const auto& log : logs) {
                const std::string& serviceName = log.first;
                const LogData& logData = log.second;

                if (consolidatedLogs.find(serviceName) == consolidatedLogs.end() || logData.timestamp > consolidatedLogs[serviceName].timestamp) {
                    consolidatedLogs[serviceName] = logData;
                }
            }
        }

        return consolidatedLogs;
    }
};

int main() {
    LogEntry logEntry;

    logEntry.addLog("micro-service-s1", LogData("INFO", "2023-07-25 10:00:00"));
    logEntry.addLog("micro-service-s1", LogData("INFO", "2023-07-15 09:00:00"));

    LogConsolidator logConsolidator;
    logConsolidator.addLogEntry(logEntry);

    std::unordered_map<std::string, LogData> consolidatedLogs = logConsolidator.consolidateLogs();

    for (const auto& entry : consolidatedLogs) {
        std::cout << entry.first << ": {\"logType\": \"" << entry.second.logType << "\", \"timestamp\": \"" << entry.second.timestamp << "\"}\n";
    }

    return 0;
}
