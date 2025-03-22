#include <iostream>
#include <rocksdb/db.h>

int main() {
    // 1. 定义 RocksDB 指针
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true; // 若数据库不存在，则创建

    // 2. 打开数据库
    rocksdb::Status status = rocksdb::DB::Open(options, "testdb", &db);
    if (!status.ok()) {
        std::cerr << "打开数据库失败: " << status.ToString() << std::endl;
        return 1;
    }

    // 3. 写入数据
    std::string key = "name";
    std::string value = "Alice";
    status = db->Put(rocksdb::WriteOptions(), key, value);
    if (!status.ok()) {
        std::cerr << "写入数据失败: " << status.ToString() << std::endl;
        delete db;
        return 1;
    }

    // 4. 读取数据
    std::string result;
    status = db->Get(rocksdb::ReadOptions(), key, &result);
    if (status.ok()) {
        std::cout << "读取到数据: " << key << " = " << result << std::endl;
    } else {
        std::cerr << "读取数据失败: " << status.ToString() << std::endl;
    }

    // 5. 关闭数据库
    delete db;
    return 0;
}
