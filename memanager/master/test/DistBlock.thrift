namespace cpp memanager

struct blockInfo{
       1:required string filePath;
       2:required i32 offset;
       3:required i64 blockSize;
       4:required string storeHost;
}

service trans_blockInfo{
	void trans_blockInfo(1:blockInfo block);
}

