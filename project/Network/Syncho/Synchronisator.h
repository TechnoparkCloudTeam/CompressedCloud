#pragma once
class ISynchronisator {
public:
	virtual void GetRequest();
	virtual void SendRequest();
	virtual void SendAnswer();
	virtual void CheckForConflicts();
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