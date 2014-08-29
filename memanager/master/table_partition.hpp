/*this cpp is about data partition
  the data that has partitioned managered by this source code.
*/

#ifndef TABLE_PARTITION_HPP
#define TABLE_PARTITION_HPP

#include "hdfs.h"
#include "Table_types.h"
#include<string>
#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;

namespace memanager{
    class table_partition{
    public:
	void addRow(const TTableRow &row);
    private:
	vector<TTableRow> partition;
	table_partition(table_partition &) = delete;
	table_partition& operator=(table_partition &) = delete;
    };

    void table_partition::addRow(const TTableRow &row){
	partition.push_back(row);
    }

}

#endif //TABLE_PARTITION_HPP

