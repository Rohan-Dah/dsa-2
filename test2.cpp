#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LogData {
public:
    string logType;
    string timestamp;

    LogData() {}
    LogData(const string& logType, const string& timestamp) : logType(logType), timestamp(timestamp) {}
};

class LogEntry {
private:
    unordered_map<string, LogData> logs;

public:
    void addLog(const string& serviceName, const LogData& logData) {
        if (logs.find(serviceName) == logs.end() || logData.timestamp > logs[serviceName].timestamp) {
            logs[serviceName] = logData;
        }
    }

    const unordered_map<string, LogData>& getLogs() const {
        return logs;
    }
};

class LogConsolidator {
private:
    vector<LogEntry> logEntries;

public:
    void addLogEntry(const LogEntry& logEntry) {
        logEntries.push_back(logEntry);
    }

    unordered_map<string, LogData> consolidateLogs() {
        unordered_map<string, LogData> consolidatedLogs;

        for (const auto& logEntry : logEntries) {
            const unordered_map<string, LogData>& logs = logEntry.getLogs();
            for (const auto& log : logs) {
                const string& serviceName = log.first;
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

    logEntry.addLog("micro-service-m1", LogData("INFO", "2023-07-25 14:00:00"));
    logEntry.addLog("micro-service-n1", LogData("ERROR", "2023-07-25 14:10:00"));
    logEntry.addLog("micro-service-o1", LogData("DEBUG", "2023-07-25 14:20:00"));
    logEntry.addLog("micro-service-n1", LogData("ERROR", "2023-07-25 14:30:00"));
    logEntry.addLog("micro-service-o1", LogData("INFO", "2023-07-25 14:40:00"));
    logEntry.addLog("micro-service-p1", LogData("DEBUG", "2023-07-25 14:50:00"));

    LogConsolidator logConsolidator;
    logConsolidator.addLogEntry(logEntry);

    unordered_map<string, LogData> consolidatedLogs = logConsolidator.consolidateLogs();

    for (const auto& entry : consolidatedLogs) {
        cout << entry.first << ": {\"logType\": \"" << entry.second.logType << "\", \"timestamp\": \"" << entry.second.timestamp << "\"}\n";
    }

    return 0;
}
