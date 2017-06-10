#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class inter {
	string line;
	string var;
public:
	void getString(string ls) {

	};
};

class value {
	string varname;
	string valstr;
	int valnum;
	float valf;
	bool valbool;
public:
	void setval(string vall) {
		stringstream ss;
		if (checkifnum(vall)) {
			ss << vall;
			ss >> valnum;
		}
		else if (checkiffloat(vall)) {
			ss << vall;
			ss >> valf;
		}
		else if (checkbool(vall)) {
			if (vall == "true") {
				valbool = true;
			}
			else {
				valbool = false;
			}
		}
		else {
			valstr = vall;
		}

	}
};


bool checkifnum(string vall) {
	/* takes in a string and check to see if the string is a number*/
	for (int i = 0; i < vall.length(); i++) {
		if (!numver(vall[i])) {
			return(false);
		}
	}
	return true;
}

//number verifier
bool numver(char vals) {
	if (vals == '1'
		|| vals == '2'
		|| vals == '3'
		|| vals == '4'
		|| vals == '5'
		|| vals == '6'
		|| vals == '7'
		|| vals == '8'
		|| vals == '9'
		|| vals == '0'
		) {
		return true;
	}
	return false;
}

bool checkiffloat(string vall) {
	int counter = 0;
	for (int i = 0; i < vall.length(); i++) {
		if (!numver(vall[i]) || vall[i] != '.') {
			return false;
		}
		if (counter == 0 && vall[i] == '.') {
			counter += 1;
		}
		else if (counter > 0 && vall[i] == '.') {
			return false;
		}
	}
	return true;
}

bool checkbool(string val) {
	if (val == "true" || val == "false") {
		return true;
	}
	return false;
}

