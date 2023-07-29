def consolidate_and_sort_logs(log_entries):
    consolidated_logs = {}

    for entry in log_entries:
        for service, log_data in entry.items():
            timestamp = log_data["timestamp"]
            log_type = log_data["log_type"]

            if service in consolidated_logs:
                existing_timestamp = consolidated_logs[service]["timestamp"]
                if timestamp > existing_timestamp:
                    consolidated_logs[service] = {"log_type": log_type, "timestamp": timestamp}
            else:
                consolidated_logs[service] = {"log_type": log_type, "timestamp": timestamp}

    sorted_logs = sorted(consolidated_logs.items(), key=lambda x: x[1]["timestamp"])

    return {service: log_data for service, log_data in sorted_logs}


# Test cases
test_case_1 = [
    {
        "micro-service-q1": {"log_type": "INFO", "timestamp": "2023-07-25 09:00:00"},
        "micro-service-r1": {"log_type": "ERROR", "timestamp": "2023-07-25 09:15:00"},
        "micro-service-s1": {"log_type": "DEBUG", "timestamp": "2023-07-25 09:30:00"},
    },
    {
        "micro-service-r1": {"log_type": "ERROR", "timestamp": "2023-07-25 09:45:00"},
        "micro-service-s1": {"log_type": "INFO", "timestamp": "2023-07-25 10:00:00"},
        "micro-service-t1": {"log_type": "DEBUG", "timestamp": "2023-07-25 10:45:00"},
        "micro-service-r1": {"log_type": "WARN", "timestamp": "2023-07-25 09:35:00"},
    },
    {
        "micro-service-s1": {"log_type": "ERROR", "timestamp": "2023-07-25 10:30:00"},
        "micro-service-t1": {"log_type": "INFO", "timestamp": "2023-07-25 10:15:00"},
        "micro-service-s1": {"log_type": "WARN", "timestamp": "2023-07-25 10:00:00"},
    }
]

test_case_2 = [
    {
        "micro-service-m1": {"log_type": "INFO", "timestamp": "2023-07-25 14:00:00"},
        "micro-service-n1": {"log_type": "ERROR", "timestamp": "2023-07-25 14:10:00"},
        "micro-service-o1": {"log_type": "DEBUG", "timestamp": "2023-07-25 14:20:00"},
        "micro-service-n1": {"log_type": "ERROR", "timestamp": "2023-07-25 14:30:00"},
        "micro-service-o1": {"log_type": "INFO", "timestamp": "2023-07-25 14:40:00"},
        "micro-service-p1": {"log_type": "DEBUG", "timestamp": "2023-07-25 14:50:00"},
    }
]

test_case_3 = [
    {
        "micro-service-s1": {"log_type": "INFO", "timestamp": "2023-07-25 10:00:00"},
        "micro-service-s1": {"log_type": "INFO", "timestamp": "2023-07-15 09:00:00"},
    }
]

# print(consolidate_and_sort_logs(test_case_1))
# print(consolidate_and_sort_logs(test_case_2))
print(consolidate_and_sort_logs(test_case_3))
