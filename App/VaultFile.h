#ifndef _VAULTFILE_H_
#define _VAULTFILE_H_

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "PasswordManagerError.h"

#define MIN_HEADER_LENGTH 86 //why this magic number?

using namespace std;

class VaultFile{
	string vaultpath;
	fstream *vaultfile;
	int headersize, vaultsize;
	bool newflag;

public:
	VaultFile();
	~VaultFile();

	int create_file(string path);
};



#endif
