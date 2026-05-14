#include <ResourceManager/ResourceManager.h>

namespace resources {
    template<typename T>
    std::shared_ptr<T> ResourceManager::load(const std::string& path) {
        auto it = resources_.find(path);

        if (it != resources_.end()) {
            return it->second;
        }

        auto resource = std::make_shared<T>();

        // 3. Загружаем
        if (!resource->load(path)) {
            return ResourceHandle<T>();  // пустой хендл при ошибке
        }

        // 4. Сохраняем в кэш
        resources_[path] = resource;

        return resource;
    }

    void ResourceManager::unload(const std::string& path) {
        auto it = resources_.find(path);

        if (it != resources_.end()) {
            it->second.reset();
            resources_.erase(path);
        }
    }
}