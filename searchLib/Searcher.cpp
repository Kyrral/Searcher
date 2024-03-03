#include "Searcher.h"

void Searcher::searchFile(const fs::path& directory, const std::string& filename)
{

	for (const auto& entry : fs::directory_iterator(directory)) {
		try {

			if (fileFound.load()) return;

			if (fs::is_regular_file(entry) && entry.path().filename() == filename) {
				fileFound.store(true);

				std::lock_guard<std::mutex> lock(mtxCount);
				std::cout << "File found: " << entry.path() << std::endl;
				return;
			}

			if (fs::is_directory(entry)) {
				mtxCount.lock();
				if (count < 8 && !fileFound.load()) {
					++count;
					std::thread(&Searcher::Worker, this, entry, filename).detach();
					std::cout << "Thread created. Amount: " << count << "\n";
					mtxCount.unlock();
				}
				else {
					mtxCount.unlock();
					searchFile(entry, filename);
				}
			}
		} catch(std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void Searcher::Worker(const fs::path& directory, const std::string& filename)
{
	if (!fileFound.load())
	{
		std::cout << directory << "\n";
		searchFile(directory, filename);
	}
	std::lock_guard<std::mutex> lock(mtxCount);
	--count;
}
