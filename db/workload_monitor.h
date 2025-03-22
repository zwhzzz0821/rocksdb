#pragma once

#include <bits/stdint-uintn.h>
#include <atomic>
#include <iostream>

namespace ROCKSDB_NAMESPACE {
class WorkloadMonitor {
public:
    static WorkloadMonitor& GetInstance();
    
    WorkloadMonitor(const WorkloadMonitor&) = delete;
    WorkloadMonitor& operator=(const WorkloadMonitor&) = delete;
    
    void RecordWrite();
    void RecordRead();
    uint32_t GetWriteCount() const;
    uint32_t GetReadCount() const;
private:
    WorkloadMonitor() : write_count_(0), read_count_(0) {}
    
    constexpr static uint32_t threshold = 1000000;
    std::atomic<uint32_t> write_count_;
    std::atomic<uint32_t> read_count_;
};
} // namespace ROCKSDB_NAMESPACE