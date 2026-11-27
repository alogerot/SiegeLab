#pragma once
#include <cyclone/body.h>
#include <cyclone/collide_fine.h>
#include <vector>
enum class ShapeKind
{
	NONE,BOX,SPHERE
};
struct PhysicsRegistration
{
	int id = -1;
	cyclone::RigidBody* body = nullptr;
	cyclone::CollisionPrimitive* colliderPtr = nullptr;
	ShapeKind kind = ShapeKind::NONE;
};

class PhysicsWorld
{
private:
	std::vector<PhysicsRegistration> registrations;
	std::vector<cyclone::CollisionPlane> planes;
public:
	void RegisterSphere(int _id,cyclone::RigidBody* _body ,cyclone::CollisionSphere* _sphere );
	void RegisterBox(int _id, cyclone::RigidBody* _body, cyclone::CollisionBox* _box);
	void RegisterPlane(cyclone::CollisionPlane plane);
	void Step(float dt);
	void UpdatePosition(PhysicsRegistration& _pr);
	bool SphereSphereCol(cyclone::CollisionSphere*, cyclone::CollisionSphere*);
	bool BoxSphereCol(cyclone::CollisionBox* _box, cyclone::CollisionSphere* _sphere);
	bool BoxBoxCol(cyclone::CollisionBox*, cyclone::CollisionBox*);
	bool SpherePlaneCol(cyclone::CollisionSphere* _sphere, cyclone::CollisionPlane _plane);
	bool BoxPlaneCol(cyclone::CollisionBox* _box, cyclone::CollisionPlane _plane);

};

