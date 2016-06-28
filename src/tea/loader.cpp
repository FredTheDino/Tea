#include "loader.h"

namespace Tea {

	std::string Loader::fsPath = "../res/";
	bool Loader::looping = false;
	bool Loader::works = false;

	std::string Loader::readTextFile(const std::string& path) {
		std::fstream file = openFile(path);
		std::string line;
		
		std::string output = "";
		while (std::getline(file, line)) {
			output += line;
			output += '\n';
		}
		return output;
	}

	std::fstream Loader::openFile(const std::string & path) {
		std::fstream file((fsPath + path).c_str());
		
		if (file.fail()) {
			std::cout << "Error loading file: " << (fsPath + path) << std::endl;
			
			//If you can't find the first file, look in the directories over this one til we find it. 
			//(If you build this in the build directory, it should just allways work.)
			if (!looping && !works) {
				
				looping = true;
				for (size_t i = 0; i < 5; i++) {
					fsPath = "../" + fsPath;
					std::cout << "fsPath: " << fsPath << std::endl;
					file = openFile(path);

					if (file.is_open()) {
						works = true;
						looping = false;
						break;
					}
				}
			}
		}
		return file;
	}

	void Loader::setFileSystemPath(const std::string & path) {
		fsPath = path;
	}
}