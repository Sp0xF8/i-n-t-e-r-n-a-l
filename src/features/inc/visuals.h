#pragma once

struct view_matrix_t {
	float* operator[](int index) {
		return matrix[index];
	}


	float matrix[4][4];
};


namespace visuals	{

	extern view_matrix_t* viewMatrix;


	void run();


	void skeleton_esp(int index);
	void box_esp(int index);
	void health_esp(int index);
	void name_esp(int index);
	void weapon_esp();
	void snaplines(int index);

}