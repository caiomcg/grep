#pragma once

#include "parse_data.h"

class ParseDataImpl : public ParseData {
public:
	void parse(int argc, char** argv) override;
	
	std::string getRegex() const override;
	std::string getPath() const override;
private:
	std::string m_regex {""};
	std::string m_path {""};
};
