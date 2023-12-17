#ifndef APPLICATION_H
#define APPLICAITON_H
#include "olcPixelGameEngine.h"
#include "World.h"
#include "Constants.h"
#include "Force.h"
#include "Graphics.h"
#include "CollisionDetection.h"
#include "Contact.h"

class Application
{
public:
	Application() = default;
	~Application() = default;

public:
	World* world;
	
	

	bool debug = false;
	
	
	
public:

	void Setup();
	void Input(olc::PixelGameEngine* ptr);
	void Update(float deltatime, olc::PixelGameEngine* ptr);
	void Render(olc::PixelGameEngine* ptr);
	void Destroy();
	
};



#endif // !APPLICATION_H


