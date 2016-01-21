#pragma once
#include <memory>
#include <vector>
#include <list>
#include "Face.h"
#include <random>

class MeshController {
private:
	std::list<Face> faces;
public:
	MeshController() {}
	void CreateField(int rows, int columns, int length, int width) {
		faces.clear();
		std::vector<std::vector<std::shared_ptr<gVector4>>> grid;
		grid.resize(rows + 1);
		for (auto& element : grid) {
			element.resize(columns + 1);
		}
		float row_size = static_cast<float>(length) / static_cast<float>(rows);
		float column_size = static_cast<float>(width) / static_cast<float>(columns);
		for (int x = 0; x < rows + 1; x++) {
			for (int y = 0; y < columns + 1; y++) {
				grid[x][y] = std::make_shared<gVector4>(row_size * static_cast<float>(x)-static_cast<float>(length) / 2.f, column_size * static_cast<float>(y)-static_cast<float>(width) / 2.f, 0.f, 1.f);
			}
		}

		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < columns; y++) {
				auto face1 = Face(grid[x][y], grid[x][y+1], grid[x+1][y+1]);
				auto face2 = Face(grid[x][y], grid[x+1][y], grid[x+1][y + 1]);
				faces.push_back(face1);
				faces.push_back(face2);
			}
		}
	}

	void Fractalize(float range) {
		range = std::abs(range);
		std::list<Face> new_faces;
		std::list<std::shared_ptr<gVector4>> new_verticies;
		for (Face face : faces) {
			auto points = face.getPoints();

			bool n1Exists = false;
			bool n2Exists = false;
			bool n3Exists = false;
			auto n1 = std::make_shared<gVector4>((*points[0] + *points[1]) / 2);
			auto n2 = std::make_shared<gVector4>((*points[1] + *points[2]) / 2);
			auto n3 = std::make_shared<gVector4>((*points[2] + *points[0]) / 2);

			for (auto vert : new_verticies) {
				if (*vert == *n1) {
					n1Exists = true;
					n1 = vert;
				}
				if (*vert == *n2) {
					n2Exists = true;
					n2 = vert;
				}
				if (*vert == *n3) {
					n3Exists = true;
					n3 = vert;
				}
			}

			Face f1(points[0], n1, n3);
			Face f2(points[1], n1, n2);
			Face f3(points[2], n2, n3);
			Face f4(n1, n2, n3);

			new_faces.push_back(f1);
			new_faces.push_back(f2);
			new_faces.push_back(f3);
			new_faces.push_back(f4);
			if (!n1Exists) { new_verticies.push_back(n1); }
			if (!n2Exists) { new_verticies.push_back(n2); }
			if (!n3Exists) { new_verticies.push_back(n3); }
		}
		faces.swap(new_faces);
		std::default_random_engine engine(NULL);
		std::uniform_real_distribution<float> random(-1.f, 1.f);
		for (auto vert : new_verticies) {
			(*vert)[2] = (*vert)[2] + random(engine)*range;
		}
	}

	std::list<Face> getFaces() { return faces; }

	std::list<std::shared_ptr<gVector4>> getVertecies() {
		std::list<std::shared_ptr<gVector4>> vertecies;
		for (Face face : faces) {
			auto points = face.getPoints();
			for (auto point : points) {
				vertecies.push_back(point);
			}
		}
		return vertecies;
	}
};