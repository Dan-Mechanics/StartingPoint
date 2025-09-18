#include <iostream>

/// dit heeft allemaal met memory managment te make ndus je moet bewust zijn.
// move sematincs.
// move constructor, minder ingewikkelde inhoud.
// R values zijn recht van het is tekene staan. L is solid, R is fly. I-value has adress, R-values are tijdelijke
// so you wanna do movements with R values so more performance. R stands for return-value.

// big three: pointers
// big five: optimizalition, move semantics, for stl
// sorteer algo, dat met move semantics heel stuk efficienter.
// bij niet-trivilae objecten is dit belangirjk

// kijk nog eens naar stl odracht en game of life en example code van big three and big five make a print.
// game of life met algorithms oplossen. als niet lukt dan lamdas. i really hope he posts the shit this time.

// big three:
// destructur, copy consutecutr, copy assigment constructor
// check slides for more infor,
// look for what big three and big five. so look at code or look at slides yahoooooooooooo
// i couldt make the game of life challenge today but i will look at it later.
// 

#pragma once
class Texture
{
	friend std::ostream& operator<<(std::ostream& os, const Texture& other);

public: 
	std::string name;
	int size;
	int* data;
	
	Texture(std::string name, int size);
	Texture(const Texture& other);
	virtual ~Texture() noexcept;
	//Texture operator::(Texture&& other);

	Texture& operator=(const Texture& other);
};

