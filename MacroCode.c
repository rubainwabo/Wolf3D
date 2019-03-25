int 	main(void)
{
	unsigned int xblock = 20;
	unsigned int yblock = 15;
	unsigned int blocksize = 32;
	unsigned int WIDTH = xblock * blocksize;
	unsigned int HEIGHT = yblock * blocksize;
//CAMERA
	float radius
	float angle;
	float fov;
	float raylength;
	float speedmove;
	flaot speedangle;
	float radius;
	vertexArray;
}

inline float toRadian(float angle)
{

}
inline float Cos(float radian)
{

}
inline float Sin(float radian)
{

}

void 	camera(void)
{
	unsigned int i;
	radius = 5;
	color = 0xff0000;
	speedangle = 100.0f;
	speedmove = 200.0f;
	position = {.x = 128, .y = 128};
	fov = 60;
	raylength = 200;
	i = -1;

	while (++i < WIDTH)
	{
		vertexArray rays; // This will fill our ray tab of our rays
	}
}

void	projection(void)
{
	unsigned 	int i;

	i = -1;
	while (++i < rays.length())
	{
		rays[i][0] = camera_position;
		rays[i][1] = (.x = camera_position.x + raylength.Cos((Cam.angle + fov/2) - i * (fov / WIDTH)),
			.y = camera_position.y + raylength.Sin((Cam.angle + fov/2) - i * (fov / WIDTH));
	}
}
void 	event(void)
{
	if (KEY = UP)
	{
		camera_position.x += Cos(camera.angle) * speedmove * time();
		camera_position.y += Sin(camera.angle) * speedmove * time();
	}
	if (KEY = DOWN)
	{
		camera_position.x -= Cos(camera.angle) * speedmove * time();
		camera_position.y -= Sin(camera.angle) * speedmove * time();
	}
	if (KEY = LEFT)
		camera_angle -= speedangle * time()
	if (KEY = RIGHT)
		camera_angle -= speedangle * time()
	if (camera_angle > 360)
		camera_angle = 0;
	if (camera_angle < 0)
		camera_angle = 360;
}