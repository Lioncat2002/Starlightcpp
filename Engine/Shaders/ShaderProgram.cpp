#include "ShaderProgram.h"



namespace Starlight {
	
	ShaderProgram::ShaderProgram(std::string VERTEXFILE, std::string FRAGMENTFILE)
	{
		vertexShaderID = loadShader(VERTEXFILE, GL_VERTEX_SHADER);
		fragmentShaderID = loadShader(FRAGMENTFILE, GL_FRAGMENT_SHADER);
		programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);
		bindAttributes();
		glLinkProgram(programID);
		glValidateProgram(programID);
	}

	void ShaderProgram::init()
	{
		glUseProgram(programID);
	}

	void ShaderProgram::dispose()
	{
		//std::cout << "bruh";
		glUseProgram(0);
	}

	ShaderProgram::~ShaderProgram()
	{
		dispose();
		glDetachShader(programID, vertexShaderID);
		glDetachShader(programID, fragmentShaderID);
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		glDeleteShader(programID);
	}

	void ShaderProgram::bindAttributes()
	{
	}

	void ShaderProgram::bindAttribute(int attribute, std::string variable)
	{

		glBindAttribLocation(programID,attribute,variable.c_str());
	}
	
	int ShaderProgram::loadShader(std::string filename, int type) {
		std::ifstream file(filename);
		std::string buffer;
		std::string src="";

		//std::cout << "bruh";
		if (file.is_open()) {
			while (file) {
				std::getline(file,buffer);
				src += buffer+'\n';
				buffer = "";
			}
			file.close();
		}
		int shaderId=glCreateShader(type);
		const char* src_str = src.c_str();
		
		glShaderSource(shaderId,1,&src_str, NULL);
		glCompileShader(shaderId);

		int success;
		char infoLog[512];
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog;
			std::exit(-1);
		}
		return shaderId;
	}
}