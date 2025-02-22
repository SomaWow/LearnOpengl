#include <iostream>

#include "texture.h"

Texture2D::Texture2D() 
	: Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
	glGenTextures(1, &this->ID);
}

void Texture2D::Generate(GLuint width, GLuint height, unsigned char* data, unsigned int format) {
	this->Width = width;
	this->Height = height;

	// 如果format = 0， 为默认设置
	if (format == 1) {
		this->Internal_Format = GL_RED;
		this->Image_Format = GL_RED;
	}
	else if (format == 3) {
		this->Internal_Format = GL_RGB;
		this->Image_Format = GL_RGB;
	}
	else if (format == 4) {
		this->Internal_Format = GL_RGBA;
		this->Image_Format = GL_RGBA;
	}

	//绑定该纹理进行设置
	glBindTexture(GL_TEXTURE_2D, this->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
	// Set Texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);
	// Unbind texture
	//解除绑定
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const {
	glBindTexture(GL_TEXTURE_2D, this->ID);
}