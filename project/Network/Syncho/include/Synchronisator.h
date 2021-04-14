#pragma once
class ISynchronisator {
public:
	virtual void GetRequest() = 0;
	virtual void SendRequest() = 0;
	virtual void SendAnswer() = 0;
	virtual void CheckForConflicts() = 0;
	virtual void GetStatus() = 0;
};

class Synchronisator : public ISynchronisator {
public:
	void GetRequest() override;
	void SendRequest() override;
	void SendAnswer() override;
	void CheckForConflicts() override;
private:
	
	void CompareFileHashes();
	void CheckFilePresence();
	void Run();
	void ShutDown();
};