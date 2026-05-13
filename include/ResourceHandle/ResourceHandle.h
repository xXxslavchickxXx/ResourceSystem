#include <memory>

namespace resources {
    template<typename T>
    class ResourceHandle {
        std::shared_ptr<T> resource;

    public:
        ResourceHandle() = default;
        ResourceHandle(std::shared_ptr<T> resource) : resource(resource) {}

        T* get() { return resource_.get(); }
        T* operator->() const { return resource.get(); }
        T& operator*() const { return *resource; }

        bool operator==(const ResourceHandle& other) const {
            return resource_ == other.resource;
        }
    };
}