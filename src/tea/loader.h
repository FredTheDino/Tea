#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "stb_image.h"

namespace Tea {

	class Loader {
	public:
		static std::string readTextFile(const std::string& path);

		static unsigned char* loadImage(const std::string& path, int* width, int* height, int* numComponents, int numComponentsHint = 0);

		static void freeImage(unsigned char* data);

		static std::fstream openFile(const std::string& path);

		static void setFileSystemPath(const std::string& path);

	private:
		static std::string fsPath;
		static bool looping;
		static bool works;
	};
}