#include "exampleResource.h"

namespace resources {
	ShaderProgram::ShaderProgram(const std::string& vPath, const std::string& fPath) { load(vPath, fPath); }

	bool ShaderProgram::load(const std::string& vPath, const std::string& fPath) {
		setPath(vPath, fPath);
		if (vertexPath.empty() || fragmentPath.empty()) {
			std::cerr << "ошибка, какой то из путей не задан!\n";
			std::cout << vertexPath << " " << fragmentPath << '\n';
			return false;
		}

		data = std::make_unique<shader::ShaderProgram>(shader::ShaderProgram::from_path(vPath, fPath));

		loaded = true;
		return true;
	}

	bool ShaderProgram::load(const std::string& path) {
		if (vertexPath.empty() || fragmentPath.empty()) {
			std::cerr << "ошибка, какой то из путей не задан!\n";
			return false;
		}
		return true;
	}

	bool ShaderProgram::unload() {
		vertexPath.clear();
		fragmentPath.clear();
		data.reset();
		loaded = false;
		return true;
	}

	void ShaderProgram::setPath(const std::string& vPath, const std::string& fPath) {
		if (fs::exists(vPath)) {
			vertexPath = fs::path(vPath);
		}
		else {
			std::cerr << "Вертексного пути не существует\n";
		}
		if (fs::exists(fPath)) {
			fragmentPath = fs::path(fPath);
		}
		else {
			std::cerr << "Фрагментного пути не существует\n";
		}
	}

	const shader::ShaderProgram* ShaderProgram::getData() const {
		return data.get();
	}
	shader::ShaderProgram* ShaderProgram::getData() {
		return data.get();
	}
}