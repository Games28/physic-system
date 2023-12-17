#include "Application.h"

void Application::Setup()
{
	world = new World(-9.8f);
	//Body* floor = new Body(BoxShape(800 - 50, 50),0 , 400, 500, 0.0f);
	//floor->restitution = 0.5f;
	//floor->movementstatic = true;
	//floor->rotationstatic = true;
	////floor->SetTexture("crate.png");
	//world->AddBody(floor);
	//
	//Body* leftWall = new Body(BoxShape(50, 400), 1, 50, 270, 0.0f);
	//leftWall->movementstatic = true;
	//leftWall->rotationstatic = true;
	//leftWall->restitution = 0.2f;
	//world->AddBody(leftWall);
	//
	//Body* rightWall = new Body(BoxShape(50, 400), 2, 720, 270, 0.0f);
	//rightWall->restitution = 0.2f;
	//rightWall->movementstatic = true;
	//rightWall->rotationstatic = true;
	//world->AddBody(rightWall);
	//
	//
	//Body* bigBox = new Body(BoxShape(100, 100),3, 400, 300, 0.0f);
	//bigBox->rotation = 0.0f;
	////bigBox->restitution = 0.7f;
	//bigBox->movementstatic = true;
	////bigBox->SetTexture("crate.png");
	//world->AddBody(bigBox);
	//
	//Vec2f wind(0.5f * PIXELS_PER_METER, 0.0f);
	//world->AddForce(wind);
	Body* a = new Body(CircleShape(30, 30), 600, 400, 0.0f);
	a->movementstatic = true;
	a->rotationstatic = true;
	Body* b = new Body(CircleShape(20, 20), a->position.x - 100, a->position.y, 1.0f);
	world->AddBody(a);
	world->AddBody(b);
	JointConstraint* joint = new JointConstraint(a, b, a->position);
	world->AddConstraint(joint);
}

void Application::Input(olc::PixelGameEngine* ptr)
{
	
	if (ptr->GetMouse(0).bPressed)
	{
		int x = ptr->GetMouseX();
		int y = ptr->GetMouseY();
		
		Body* box = new Body(BoxShape(50,50), x, y, 2.0);
		box->restitution = 0.1f;
		box->friction = 0.7f;
		
		world->AddBody(box);
	}
	if (ptr->GetMouse(1).bPressed)
	{
		int x = ptr->GetMouseX();
		int y = ptr->GetMouseY();
		
		Body* ball = new Body(CircleShape(20,20), x, y, 2.0);
		ball->restitution = 0.1f;
		ball->friction = 0.7f;

		world->AddBody(ball);
	}
	
}

void Application::Update(float deltatime,olc::PixelGameEngine* ptr) 
{
	if (deltatime > 0.017)
	{
		deltatime = 0.017f;
	}
	
	world->Update(ptr, deltatime);
	

	

	
}

void Application::Render(olc::PixelGameEngine* ptr)
{

	
	for (auto& body : world->GetBodies())
	{
		
		if (body->shape->GetType() == CIRCLE)
		{
			
			CircleShape* circleshape = (CircleShape*)body->shape;
			Graphics::DraweWireFrameModel(ptr, circleshape->vertices, body->position.x, body->position.y,body->rotation, circleshape->radius, 0xffff5500);
			//ptr->FillCircle(body->position.x, body->position.y, circleshape->radius, color);
		}
		if(body->shape->GetType() == BOX)
		{
			
			BoxShape* boxShape = (BoxShape*)body->shape;
			
			
				
			
			
			

			//ptr->DrawSprite(body->position.x, body->position.y, body->sprite);
				//for (int i = 0; i < boxShape->worldvertices.size(); i++)
				//{
				//	ptr->FillCircle({ int(boxShape->worldvertices[i].x),int(boxShape->worldvertices[i].y) }, 4, olc::CYAN);
				//}
			
			
			Graphics::DrawPolygon(ptr, body->position.x, body->position.y, boxShape->worldvertices, 0xff00ff00);
			
			
		}
		if (body->shape->GetType() == POLYGON)
		{
			PolygonShape* polygonShape = (PolygonShape*)body->shape;
			Graphics::DrawPolygon(ptr, body->position.x, body->position.y, polygonShape->worldvertices, 0xff00ff00);
		}
	}
}

void Application::Destroy()
{
	delete world;
}


