#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

namespace resources {
	class Resource {
	public:
		virtual bool load(const std::string& path) = 0;
		virtual bool unload() = 0;

	protected:
		bool loaded = false;
	};

	template<typename RType>
	class TypedResource : public Resource {
	public:
		virtual const RType* getData() const = 0;
		virtual RType* getData() = 0;

	};
}