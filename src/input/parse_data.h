#pragma once

#include <string>

class ParseData {
public:
	virtual ~ParseData() {}
	
	virtual void parse(int argc, char** argv) = 0;
	virtual std::string getRegex() const = 0;
	virtual std::string getPath() const = 0;
};

