#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

namespace resources {
	class Resource {
	public:
		virtual bool load();
		virtual bool unload();

		const fs::path& getPath() const { return path; }

		void setPath(const std::string& path) {
			if(fs::exists(path))
				this->path = fs::path(path);
		}

	protected:
		fs::path path;
		bool loaded = false;
	};

	template<typename RType>
	class TypedResource : Resource {
	public:
		virtual const RType* getData() const = 0;
		virtual RType* getData() = 0;

	};
}