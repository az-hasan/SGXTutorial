/* 
 * |Aisha Hasan|
 * 
 * The |PasswordManagerCore.h| file.
 *  
 */

#ifndef _PASS_MAN_CORE_H_
#define _PASS_MAN_CORE_H_

#include <fstream>
#include <iostream>
#include <cstdlib>

#include "Enclave_u.h"
#include "PasswordManagerError.h"
#include "VaultFile.h"
#include "EnclaveBridge.h"

#define SUCCESS 1 

using namespace std;

class PasswordManagerCore{

	int num;
	string dummyaccount;
	VaultFile vaultfile;

	public:
		PasswordManagerCore(void);
		~PasswordManagerCore(void);

		int vault_create(string path);
		int vault_destroy(void);
		int vault_get_count_all(int *count);
		int vault_get_info(int ndx, string *account_name);

};

#endif
