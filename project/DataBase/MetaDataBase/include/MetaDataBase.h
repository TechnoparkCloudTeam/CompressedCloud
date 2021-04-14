#pragma once


class IMetaDataBase {
public:
	virtual void GetRequest() = 0;
	virtual void AddUser() = 0;
	virtual void CheckUser() = 0;
	virtual void DeleteUser() = 0;
	virtual void AddUserToDir() = 0;
	virtual void UpdateDirInfo() = 0;
	virtual void RemoveUserFromDir() = 0;
	virtual void GetStatus() = 0;

};

class MetaDataBase : public IMetaDataBase {
public:
	void GetRequest() override;
	void AddUser() override;
	void CheckUser() override;
	void DeleteUser() override;
	void AddUserToDir() override;
	void UpdateDirInfo() override;
	void RemoveUserFromDir() override;
	void GetStatus() override;	
};