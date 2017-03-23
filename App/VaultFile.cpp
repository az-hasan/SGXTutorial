#include "VaultFile.h"

using namespace std;

//constructor
VaultFile::VaultFile(void){
	headersize = MIN_HEADER_LENGTH;
	vaultsize = 0;
	newflag = false;
}

//destructor
VaultFile::~VaultFile(void){
	//someone will need to delete this object after it's been used!
}

int VaultFile::create_file(string path){
  
    ofstream testvaultfile;

    if(ifstream(path)){ //check existing file
        cout << "AISHAPRINT FILE: " << __FILE__ << " LINE:" << __LINE__ << " " <<
            "testvault file already exists \n";
        return NL_STATUS_OK;
    }   
    
    cout << "AISHAPRINT FILE: " << __FILE__ << " LINE:" << __LINE__ << " " <<
        "testvault file doesn't already exist\n";
    testvaultfile.open(path, fstream::out);

    if(!testvaultfile){ //check if new file created
        cout << "AISHAPRINT FILE: " << __FILE__ << " LINE:" << __LINE__ << " " <<
            "testvault file could not be created";
        return NL_STATUS_OK;
    }
    else{
        cout << "AISHAPRINT FILE: " << __FILE__ << " LINE:" << __LINE__ << " " <<
            "testvault file created!\n";
        testvaultfile.close();
		vaultpath = path;
		newflag = true;
    }

    return NL_STATUS_OK;
}
