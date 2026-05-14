#include <Resource/Resource.h>
#include <shaderProgram/ShaderProgram.h>

#include <string>
#include <memory>

namespace resources {
	class ShaderProgram : public TypedResource<shader::ShaderProgram> {
		fs::path vertexPath, fragmentPath;
		std::unique_ptr<shader::ShaderProgram> data;
	
	public:
		ShaderProgram() = default;
		ShaderProgram(const std::string& vPath, const std::string& fPath);

		bool load(const std::string& vPath, const std::string& fPath);
		bool load() override;

		bool unload() override;

		void setPath(const std::string& vPath, const std::string& fPath);

		const shader::ShaderProgram* getData() const override;
		shader::ShaderProgram* getData() override;
	};
}