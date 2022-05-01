#pragma once

#define MAX_JCRENDER_MESH	1000

struct ITEM_RENDER_MESH
{
	int ItemIndex;
	float ColorR;
	float ColorG;
	float ColorB;
};

class JCRenderMesh
{
public:
	JCRenderMesh();
	virtual ~JCRenderMesh();
	void Load(char * path);
	void SetInfo(ITEM_RENDER_MESH info);
public:
	ITEM_RENDER_MESH m_JCRenderMesh[ MAX_JCRENDER_MESH ];

}; extern JCRenderMesh JCRender;