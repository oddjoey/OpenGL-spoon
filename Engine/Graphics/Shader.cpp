#include "Shader.h"

std::string Shader::getFileContents(const char* fileName)
{
	std::ifstream in(fileName, std::ios::binary);

	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}

	throw(errno);
}

void Shader::CheckCompileErrors(const unsigned int& shader, const char* type)
{
	// Stores status of compilation
	GLint hasCompiled;
	// Character array to store error message in
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}

GLint Shader::GetUniformLocation(const std::string& uniformName)
{
	if (uniformLocationCache.find(uniformName) != uniformLocationCache.end())
		return uniformLocationCache[uniformName];

	auto location = glGetUniformLocation(_ID, uniformName.c_str());
	if (location == -1)
		std::cout << "no uniform under " << uniformName << '\n';

	uniformLocationCache[uniformName] = location;
	return location;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = getFileContents(vertexFile);
	std::string fragmentCode = getFileContents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Create vertex shader w/ source
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShaderID, 1, &vertexSource, NULL);
	glCompileShader(_vertexShaderID);
	CheckCompileErrors(_vertexShaderID, "VERTEX");

	// Create fragment shader w/ source
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);					// Creating a Vertex Shader Object and grabbing its &
	glShaderSource(_fragmentShaderID, 1, &fragmentSource, NULL);				// Attatch vertex shader source to the Vertex Shader Object
	glCompileShader(_fragmentShaderID);										// Compile the Vertex Shader Object to machine code
	CheckCompileErrors(_fragmentShaderID, "FRAGMENT");

	// Create and link shader program w/ shaders
	_ID = glCreateProgram();
	glAttachShader(_ID, _vertexShaderID);
	glAttachShader(_ID, _fragmentShaderID);
	glLinkProgram(_ID);
	CheckCompileErrors(_ID, "PROGRAM");

	//BindAttribute(0, "position");
	//BindAttribute(1, "texture");
}

Shader::~Shader()
{
	Delete();
}

void Shader::Activate() const
{
	glUseProgram(_ID);
}

void Shader::Delete() const
{
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
	glDeleteProgram(_ID);
}

void Shader::SetUniform1i(const std::string& name, const GLint& value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform1f(const std::string& name, const float& value)
{
	glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string& name, const float& v0, const float& v1, const float& v2, const float& v3)
{
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::BindAttribute(const GLuint& attribute, const char* variableName) const
{
	glBindAttribLocation(_ID, attribute, variableName);
}

GLuint Shader::GetID() const
{
	return _ID;
}
