#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace Tea {
	enum class FileType {
		TEXT,
		BINARY,

	};

	class Loader {
	public:
		static std::string readTextFile(const std::string& path);

		static std::fstream openFile(const std::string& path);

		static void setFileSystemPath(const std::string& path);

	private:
		static std::string fsPath;
		static bool looping;
		static bool works;
	};
}