/*
 * |Aisha Hasan|
 *
 * The |PasswordManagerCore.cpp| file.
 * 
 * Intel's Windows tutorial version of this file interacts with the C# GUI
 * and marshalls data to the native (enclave) layer.
 *
 * Contains functions to lock/unlock/open vault, set account info/pass, get
 * account info/pass/count, set/change master_password, generate password,
 * update vault (not sure what this does yet?).
 */

#include "PasswordManagerCore.h"

PasswordManagerCore::PasswordManagerCore(void){
	num = 444;
	dummyaccount = "SEPTEMBER";
	//std::cout << "AISHA PRINT: num value created: " << num << "\n";
}

PasswordManagerCore::~PasswordManagerCore(void){
	num = 400;
	//std::cout << "AISHA PRINT: num value before destroy: " << num << "\n"; 
}

int PasswordManagerCore::vault_create(std::string path){
	int rv = SUCCESS;
	std::cout << "AISHA PRINT: creating vault: " << path  << "\n";
	return rv;
}

int PasswordManagerCore::vault_get_count_all(int *count){
	int rv = SUCCESS;
	*count = SUCCESS;
	return rv;
}

int PasswordManagerCore::vault_get_info(int ndx, std::string *account_name){
	int rv = SUCCESS;
	*account_name = dummyaccount[ndx];
	return rv;
}
