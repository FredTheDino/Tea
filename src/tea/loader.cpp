#include "loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Tea {


	std::string Loader::fsPath = "../res/";
	bool Loader::looping = false;
	bool Loader::works = false;

	std::string Loader::readTextFile(const std::string& path) {
		std::fstream file = openFile(path);
		std::string line;
		
		if (!file.is_open()) {
			std::cout << "Loader error: File does not exists " << fsPath + path << std::endl;
		}
	
		std::string output = "";
		while (std::getline(file, line)) {
			output += line;
			output += '\n';
		}
		return output;
	}

	unsigned char * Loader::loadImage(const std::string& path, int* width, int* height, int* numComponents, int numComponentsHint) {
		if (!works) {
			std::fstream f = openFile(path);
			f.close();
		}
		return stbi_load((fsPath + path).c_str(), width, height, numComponents, numComponentsHint);
	}

	void Loader::freeImage(unsigned char* data) {
	  stbi_image_free(data);
	}

	std::fstream Loader::openFile(const std::string & path) {
		std::fstream file((fsPath + path).c_str());
		
		if (file.fail()) {
			std::cout << "Error loading file: " << (fsPath + path) << std::endl;
			
			//If you can't find the first file, look in the directories over this one until we find it. 
			//(If you build this in the build directory, it should just allways work.)
			if (!looping && !works) {
				looping = true;
				std::string oldPath = fsPath;

				for (size_t i = 0; i < 5; i++) {
					fsPath = "../" + fsPath;
					std::cout << "fsPath: " << fsPath << std::endl;
					file = openFile(path);

					if (file.is_open()) {
						works = true;
						looping = false;
						return file;
					}
				}
				fsPath = oldPath;
				looping = false;
			}
		}
		return file;
	}

	void Loader::setFileSystemPath(const std::string & path) {
		fsPath = path;
	}
}
