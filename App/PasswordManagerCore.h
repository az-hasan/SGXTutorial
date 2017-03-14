/* 
 * |Aisha Hasan|
 * 
 * The |PasswordManagerCore.h| file.
 *  
 */

#ifndef _PASS_MAN_CORE_H_
#define _PASS_MAN_CORE_H_

#include <iostream>
#include <cstdlib>

#define SUCCESS 1 

class PasswordManagerCore{

	int num;
	std::string dummyaccount;

	public:
		PasswordManagerCore(void);
		~PasswordManagerCore(void);

		int vault_create(std::string path);
		int vault_get_count_all(int *count);
		int vault_get_info(int ndx, std::string *account_name);

};

#endif
