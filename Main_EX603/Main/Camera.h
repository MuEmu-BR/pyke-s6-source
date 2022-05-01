#pragma once

#define ROTATION_SENS	5//5
#define ZOOM_MAX		60//60
#define ZOOM_MIN		15
#define ZOOM_INTER		1
#define CAMERA_DEBUG	0
#define PERCF(x, y)		((float)x / 100.0f * (float)y)
// ----------------------------------------------------------------------------------------------

typedef struct
{
	float* RotX;
	float	Zoom;
	float	RotationY;
	float	RotationZ;
	float	PositionZ;
	double	ClipX;
	float	ClipY;
	double	ClipZ;
	double	ClipX2;
	float	ClipY2;
	float	ClipZ2;
	float	ClipGL;
	//
	float	Z3;
	float	Z6;
	float	Y3;
	float	Y6;
} DefaultData, *lpDefData;

// ----------------------------------------------------------------------------------------------

struct CAMERA_ADDR
{
	float* Zoom;
	float* RotX;
	float* RotY;
	double* PosZ;
	double* ClipX[2];
	float* ClipY[2];
	float* ClipGL;
};


class Camera
{
public:
	Camera();
	~Camera();

	void		Load();
	// ----
	void		Init();
	void		Switch();
	void		Run(MOUSEHOOKSTRUCTEX * Mouse, WPARAM wParam);
	void		Rotate();
	static void RotateDmg(float& X, float& Y, float D);
	static void RotateFix();
	// ----
	bool		IsActive;
	float		ZoomPercent;
	void		Reset();
	// ----
	DefaultData Default;
private:
	BYTE		RotateMode;
	CAMERA_ADDR m_Address;
	bool		InMove;
	int			TempCursorX;
	int			TempCursorY;
	// ----
}; extern Camera gCamera;
// ----------------------------------------------------------------------------------------------