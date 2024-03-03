#pragma once
#include <string>
#include <thread>
#include <filesystem>
#include <iostream>
#include <atomic>
#include <mutex>

namespace fs = std::filesystem;

class Searcher
{
private:
	std::mutex mtxCount;
	int count = 0;
	std::atomic<bool> fileFound = false;
	void Worker(const fs::path& directory, const std::string& filename);

public:
	
	void searchFile(const fs::path& directory, const std::string& filename);
};