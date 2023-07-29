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
        logs[serviceName] = logData;
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

// Comparator function for sorting logs in descending order based on timestamp
bool compareLogs(const pair<string, LogData>& a, const pair<string, LogData>& b) {
    return a.second.timestamp > b.second.timestamp;
}

int main() {
    LogEntry logEntry1, logEntry2, logEntry3;

    logEntry1.addLog("micro-service-q1", LogData("INFO", "2023-07-25 09:00:00"));
    logEntry1.addLog("micro-service-r1", LogData("ERROR", "2023-07-25 09:15:00"));
    logEntry1.addLog("micro-service-s1", LogData("DEBUG", "2023-07-25 09:30:00"));

    logEntry2.addLog("micro-service-r1", LogData("ERROR", "2023-07-25 09:45:00"));
    logEntry2.addLog("micro-service-s1", LogData("INFO", "2023-07-25 10:00:00"));
    logEntry2.addLog("micro-service-t1", LogData("DEBUG", "2023-07-25 10:45:00"));
    logEntry2.addLog("micro-service-r1", LogData("WARN", "2023-07-25 09:35:00"));

    logEntry3.addLog("micro-service-s1", LogData("ERROR", "2023-07-25 10:30:00"));
    logEntry3.addLog("micro-service-t1", LogData("INFO", "2023-07-25 10:15:00"));
    logEntry3.addLog("micro-service-s1", LogData("WARN", "2023-07-25 10:00:00"));

    LogConsolidator logConsolidator;
    logConsolidator.addLogEntry(logEntry1);
    logConsolidator.addLogEntry(logEntry2);
    logConsolidator.addLogEntry(logEntry3);

    unordered_map<string, LogData> consolidatedLogs = logConsolidator.consolidateLogs();

    // Convert the map to a vector of pairs for sorting
    vector<pair<string, LogData>> sortedLogs(consolidatedLogs.begin(), consolidatedLogs.end());
    sort(sortedLogs.begin(), sortedLogs.end(), compareLogs);

    // Displaying the output
    for (const auto& entry : sortedLogs) {
        cout << "{" << entry.first << ": {\"logType\": \"" << entry.second.logType << "\", \"timestamp\": \"" << entry.second.timestamp << "\"}}\n";
    }

    return 0;
}
