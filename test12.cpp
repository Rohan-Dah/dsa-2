#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LogData {
public:
    string log_type;
    string timestamp;

    LogData() {}
    LogData(const string& log_type, const string& timestamp) : log_type(log_type), timestamp(timestamp) {}
};

class LogEntry {
private:
    unordered_map<string, vector<LogData>> logs;

public:
    void addLog(const string& serviceName, const LogData& logData) {
        logs[serviceName].push_back(logData);
    }

    const unordered_map<string, vector<LogData>>& getLogs() const {
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
            const unordered_map<string, vector<LogData>>& logs = logEntry.getLogs();
            for (const auto& log : logs) {
                const string& serviceName = log.first;
                const vector<LogData>& logDataList = log.second;

                for (const auto& logData : logDataList) {
                    if (consolidatedLogs.find(serviceName) == consolidatedLogs.end() || logData.timestamp > consolidatedLogs[serviceName].timestamp) {
                        consolidatedLogs[serviceName] = logData;
                    }
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
    LogEntry logEntry1;

    logEntry1.addLog("micro-service-m1", LogData("INFO", "2023-07-25 14:00:00"));
    logEntry1.addLog("micro-service-n1", LogData("ERROR", "2023-07-25 14:10:00"));
    logEntry1.addLog("micro-service-o1", LogData("DEBUG", "2023-07-25 14:20:00"));
    logEntry1.addLog("micro-service-n1", LogData("ERROR", "2023-07-25 14:30:00"));
    logEntry1.addLog("micro-service-o1", LogData("INFO", "2023-07-25 14:40:00"));
    logEntry1.addLog("micro-service-p1", LogData("DEBUG", "2023-07-25 14:50:00"));

    LogConsolidator logConsolidator;
    logConsolidator.addLogEntry(logEntry1);

    unordered_map<string, LogData> consolidatedLogs = logConsolidator.consolidateLogs();

    // Convert the map to a vector of pairs for sorting
    vector<pair<string, LogData>> sortedLogs(consolidatedLogs.begin(), consolidatedLogs.end());
    sort(sortedLogs.begin(), sortedLogs.end(), compareLogs);

    // Displaying the output
    for (const auto& entry : sortedLogs) {
        cout << "{" << entry.first << ": {\"log_type\": \"" << entry.second.log_type << "\", \"timestamp\": \"" << entry.second.timestamp << "\"}}\n";
    }

    return 0;
}
