#pragma once


class IMetaDataBase {
public:
	virtual void GetRequest() = 0;
	virtual void AddUser();
	virtual void CheckUser();
	virtual void DeleteUser();
	virtual void AddUserToDir();
	virtual void UpdateDirInfo();
	virtual void RemoveUserFromDir();
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