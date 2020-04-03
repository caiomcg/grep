#include "parse_data_impl.h"

#include <unistd.h>

#include <stdexcept>

void ParseDataImpl::parse(int argc, char** argv) {
	// TODO: use getOpt to fetch the parameters
	// TODO: incremente pointer by return of getOpt
	// TODO: Save the values
	int ch = 0;	
		
	while((ch = getopt(argc, argv, "r:")) != -1) {
		switch (ch) {
			case 'r':
				m_regex = std::string(optarg);
				break;
			case '?':
				throw std::runtime_error("Unknown argument");
				break; 
		}
	}

	if (m_regex.empty()) {
		throw std::runtime_error("No valid parameter for -r. Expected a regular expression");
	}	

	argc -= optind;
	argv += optind;

	if (argc > 0) {
		m_path = std::string(argv[0]);
	} else {
		throw std::runtime_error("No known path");
	}
}

std::string ParseDataImpl::getRegex() const {
	return m_regex;
}

std::string ParseDataImpl::getPath() const {
	return m_path;
}
