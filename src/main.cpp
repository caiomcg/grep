#include <iostream>
#include <fstream>
#include <regex>

#include "input/parse_data_impl.h"

void search(const std::string& output_path, std::regex regex, std::ifstream& input_stream) {
	std::string line;
	std::smatch match;

	while (std::getline(input_stream, line)) {
		// regex_match or search?
		if (std::regex_search(line, match, regex)) {
        	if (match.ready()){
     			std::cout << output_path << ":" << line << std::endl;
			}	
    	}
	}

}

int main(int argc, char** argv) {
	auto data_parser = ParseDataImpl();
	
	try {
		data_parser.parse(argc, argv);
	} catch (std::runtime_error& e) {
		std::cerr << "Could not parse the given arguments: what() - " << e.what() << std::endl;
		return 1;		
	}

	std::ifstream file_stream(data_parser.getPath());
	
	if (!file_stream.is_open()) {
		std::cerr << "Unable to find the desirede file" << std::endl;
		return 1;
	}	

	search(data_parser.getPath(), std::regex(data_parser.getRegex()), file_stream);
	
	return 0;
}
