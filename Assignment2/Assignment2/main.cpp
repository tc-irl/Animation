#include "CoreEngine.h"

class Assignment2 : public Game
{
public:
	Assignment2() {}

	virtual void Init();
protected:
private:
	Assignment2(const Assignment2& other) {}
	void operator=(const Assignment2& other) {}
};

void Assignment2::Init()
{
	GameObject* planeObject = new GameObject();
	GameObject* pointLightObject = new GameObject();
	GameObject* spotLightObject = new GameObject();
	GameObject* directionalLightObject = new GameObject();

	planeObject->AddComponent(new MeshRenderer(new Mesh("./res/models/plane3.obj"), new Material(new Texture("bricks.jpg"), 1, 8)));
	planeObject->GetTransform().SetPos(Vector3f(0, -1, 5));
	planeObject->GetTransform().SetScale(4.0f);

	pointLightObject->AddComponent(new PointLight(Vector3f(0,1,0),0.4f,Attenuation(0,0,1)));
	pointLightObject->GetTransform().SetPos(Vector3f(7,0,7));

	spotLightObject->AddComponent(new SpotLight(Vector3f(0,1,1),0.4f,Attenuation(0,0,0.1f),0.7f));
	spotLightObject->GetTransform().SetRot(Quaternion(Vector3f(0,1,0), ToRadians(90.0f)));

	directionalLightObject->AddComponent(new DirectionalLight(Vector3f(1,1,1), 0.4f));

	GameObject* testMesh1 = new GameObject();
	GameObject* testMesh2 = new GameObject();

	testMesh1->GetTransform().SetPos(Vector3f(0, 2, 0));
	testMesh1->GetTransform().SetRot(Quaternion(Vector3f(0,1,0), 0.4f));
	testMesh1->GetTransform().SetScale(1.0f);

	testMesh2->GetTransform().SetPos(Vector3f(0, 0, 25));

	testMesh1->AddChild(testMesh2);

	AddToScene(planeObject);
	AddToScene(pointLightObject);
	AddToScene(spotLightObject);
	AddToScene(directionalLightObject);
	AddToScene(testMesh1);
	testMesh2->AddChild((new GameObject())
		->AddComponent(new Camera(Matrix4f().InitPerspective(ToRadians(70.0f), Window::GetAspect(), 0.1f, 1000.0f)))
		->AddComponent(new FreeLook())
		->AddComponent(new FreeMove()));

	directionalLightObject->GetTransform().SetRot(Quaternion(Vector3f(1,0,0), ToRadians(-45)));
}

int main(int argc, char** argv)
{
	CoreEngine *engine = new CoreEngine(800,600,60,new Game());
	engine->CreateWindow("Assignment 2 - Arm Animation");
	engine->Start();
}
