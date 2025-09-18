#include "Texture.h"

Texture::Texture(std::string name, int size) : name{ name }, size{ size }, data{ new int[size] } {
	std::cout << "create" << *this << std::endl;
}

Texture::Texture(const Texture& other) : name{ other.name }, size{ other.size } {
	std::cout << "ctor" << *this << std::endl;
	this->data = new int[size];
}

Texture::~Texture() noexcept {
	std::cout << "dtor" << *this << std::endl;
	delete data;
}

Texture& Texture::operator=(const Texture& other)  {
	std::cout << "assigment" << *this << std::endl;
	
	if (this == &other) return *this;

	delete[] data;

	this->name = other.name;
	this->size = other.size;
	this->data = new int[size];
	std::copy(other.data, other.data + other.size, data);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Texture& texture) {
	os << texture.name << texture.size << texture.data << &texture;
	return os;
}
