#include "Shader.h"

std::string getFileContents(const char* fileName)
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

void CheckCompileErrors(unsigned int shader, const char* type)
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

	// Clean up shaders since they're already loaded into shader program
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

Shader::~Shader()
{
	Delete();
}

void Shader::Activate()
{
	glUseProgram(_ID);
}

void Shader::Delete()
{
	glDeleteProgram(_ID);
}

GLuint Shader::GetID() const
{
	return _ID;
}
