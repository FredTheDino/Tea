#pragma once

#include <string>
#include <fstream>
#include <iostream>

//#include "stb_image.h"

namespace Tea {

	/*
	  "Loader" loads images and files to RAM. This is 
	  usually handled for you, but if it's not, keep 
	  in mind that you need to free the RAM.
	*/
	
	class Loader {
	public:
		// Read a textfile, it's as simple as that.
		static std::string readTextFile(const std::string& path);

		// Load an image to a buffer, it should work with PNG and JPG,
		// but might even work with more
		static unsigned char* loadImage(const std::string& path,
						int* width, int* height,
						int* numComponents, int numComponentsHint = 0);

		// Frees the data associated with the buffer.
		static void freeImage(unsigned char* data);

		// A function to open a file in the resource path.
		static std::fstream openFile(const std::string& path);

		// If you wish to set where the engine looks for resources.
		static void setFileSystemPath(const std::string& path);

	private:
		// The current file system path
		static std::string fsPath;
		// If it hans't found what it's looking for and
		// is running the search loop.
		static bool looping;
		// If the loader has found a file it wants to load.
		static bool works;
	};
}
