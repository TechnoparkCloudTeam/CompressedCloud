#pragma once

#include<string>

class IFileStorage {
public:
	virtual void SendData() = 0;

	virtual void GetRequest() = 0;

	virtual void DeleteFiles() = 0;

	virtual void MakeDir() = 0;

	virtual void DeleteDir() = 0;

	virtual void GetStatus() = 0;
};



class FileStorage : public IFileStorage {
public:
	void SendData() override;

	void GetRequest() override;

	void DeleteFiles() override;

	void MakeDir() override;

	void DeleteDir() override;

	void GetStatus() override;
	
private:
	void UpdateFiles();
	void UpdateDir();
	void Run();
	void ShutDown();
};

