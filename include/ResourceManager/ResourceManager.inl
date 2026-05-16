namespace resources {
    inline std::unordered_map<std::string, std::shared_ptr<Resource>> ResourceManager::resources;

    template<typename T>
    std::shared_ptr<T> ResourceManager::load(const std::string& path) {
        auto it = resources.find(path);

        if (it != resources.end()) {
            return std::static_pointer_cast<T>(it->second);
        }

        auto resource = std::make_shared<T>();

        if (!resource->load(path)) {
            return std::shared_ptr<T>();
        }

        resources[path] = resource;

        return resource;
    }

    void ResourceManager::unload(const std::string& path) {
        auto it = resources.find(path);

        if (it != resources.end()) {
            it->second.reset();
            resources.erase(path);
        }
    }
}