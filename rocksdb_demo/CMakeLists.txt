cmake_minimum_required(VERSION 3.10)
project(RocksDBDemo)

set(CMAKE_CXX_STANDARD 17)

# 设置 RocksDB 头文件路径
include_directories(/home/zwh/DB/rocksdb/include)
include_directories(/home/zwh/DB/rocksdb/monitoring)

# 生成可执行文件
add_executable(rocksdb_demo main.cpp)

# 链接 RocksDB 静态库
target_link_libraries(rocksdb_demo /home/zwh/DB/rocksdb/librocksdb.a)
