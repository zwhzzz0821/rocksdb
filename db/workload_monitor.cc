#include "db/workload_monitor.h"

namespace ROCKSDB_NAMESPACE {
WorkloadMonitor& WorkloadMonitor::GetInstance() {
  static WorkloadMonitor instance;
  return instance;
}

void WorkloadMonitor::RecordWrite() {
  write_count_.fetch_add(1);
  uint32_t write_count = write_count_.load();
  uint32_t read_count = read_count_.load();
  uint32_t total_count = write_count + read_count;
  if (total_count >= threshold) {
    // TODO: Call to AutoTurnning
    std::cout << "Call to AutoTurnning, "
              << "Now write_count_ = " << write_count << ", "
              << "Now read_count_ = " << read_count << std::endl;
  }
}
void WorkloadMonitor::RecordRead() {
  read_count_.fetch_add(1);
  uint32_t write_count = write_count_.load();
  uint32_t read_count = read_count_.load();
  uint32_t total_count = write_count + read_count;
  if (total_count >= threshold) {
    // TODO: Call to AutoTurnning
  }
}
uint32_t WorkloadMonitor::GetWriteCount() const { return write_count_.load(); }
uint32_t WorkloadMonitor::GetReadCount() const { return read_count_.load(); }
}  // namespace ROCKSDB_NAMESPACE
