#pragma once

#include <string>
#include <memory>
#include <map>

namespace Renderer
{
	class ShaderProgram;
}

class ShaderProgram;

class ResourceManager{
public:
	ResourceManager(const std::string& executablePath);
	~ResourceManager() = default;

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete; // assignment operator
	ResourceManager& operator=(ResourceManager&&) = delete; // assignment-move operator
	ResourceManager(ResourceManager&&) = delete;

	std::shared_ptr<Renderer::ShaderProgram> loadShader(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	std::shared_ptr<Renderer::ShaderProgram> getShader(const std::string& shaderName);

private:
	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
	ShaderProgramsMap m_shaderPrograms;
	std::string m_path;
};