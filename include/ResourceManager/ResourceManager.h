#include <memory>
#include <string>
#include <unordered_map>

namespace resources {
    class Resource;

    class ResourceManager {
        static std::unordered_map<std::string, std::shared_ptr<Resource>> resources;

    public:
        template<typename T>
        static std::shared_ptr<T> load(const std::string& path);

        static void unload(const std::string& path);
    };
}

#include "ResourceManager.inl"