#pragma once
#include "gMatrix4.h"
#include <memory>
#include <vector>

class Face {
private:
	std::vector<std::shared_ptr<gVector4>> verticies;
public:
	Face(std::shared_ptr<gVector4> v1, std::shared_ptr<gVector4> v2, std::shared_ptr<gVector4> v3) {
		verticies.push_back(v1);
		verticies.push_back(v2);
		verticies.push_back(v3);
	}

	const std::vector<std::shared_ptr<gVector4>> getPoints() {
		return verticies;
	}
};