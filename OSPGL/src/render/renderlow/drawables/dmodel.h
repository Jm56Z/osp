#pragma once

#include "../drawable.h"
#include "../shader.h"
#include "../mesh.h"

/*
	A dmodel draws given vertex array as given 
	GL_Model, applying given shader following
	the dmodel standard.

	If sh is null it will use the global shader (g_shader).

	Every dmodel compatible shader must take:

	Layouts:
		vec3 vertex position (location = 0)
		vec3 vertex color (location = 1)

	Uniforms:		
		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;


*/
class dmodel : public drawable
{
public:

	mesh* mh;

	transform tform;

	shader* sh = NULL;

	uint draw_type = GL_TRIANGLES;

	virtual void draw(glm::mat4 view, glm::mat4 proj) override;

	dmodel(mesh* mh);
	dmodel(mesh* mh, shader* sh, uint draw_type = GL_TRIANGLES);
	~dmodel();
};

