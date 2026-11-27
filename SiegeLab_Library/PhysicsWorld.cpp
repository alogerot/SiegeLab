#include "PhysicsWorld.h"

void PhysicsWorld::RegisterSphere(int _id, cyclone::RigidBody* _body, cyclone::CollisionSphere* _sphere)
{
	registrations.push_back(PhysicsRegistration{.id = _id, .body = _body, .colliderPtr = _sphere});
}

void PhysicsWorld::RegisterBox(int _id, cyclone::RigidBody* _body, cyclone::CollisionBox* _box)
{
	registrations.push_back(PhysicsRegistration{ .id = _id, .body = _body, .colliderPtr = _box });
}

void PhysicsWorld::RegisterPlane(cyclone::CollisionPlane plane)
{
	planes.push_back(plane);
}

void PhysicsWorld::Step(float dt)
{
	
}

void PhysicsWorld::UpdatePosition(PhysicsRegistration& _pr)
{
	_pr.colliderPtr->body->setPosition(_pr.body->getPosition());
}

bool PhysicsWorld::SphereSphereCol(cyclone::CollisionSphere* sphereA, cyclone::CollisionSphere* sphereB)
{
	cyclone::Vector3 delta = sphereA->body->getPosition() - sphereB->body->getPosition();
	cyclone::real distance = delta.magnitude();
	if (distance <= sphereA->radius + sphereB->radius)
		return true;
	return false;
}

bool PhysicsWorld::BoxSphereCol(cyclone::CollisionBox* _box, cyclone::CollisionSphere* _sphere)
{
	cyclone::Vector3 boxPoints[8];
	boxPoints[0] = _box->body->getPosition() + _box->halfSize;
	boxPoints[1] = _box->body->getPosition() + cyclone::Vector3(-_box->halfSize.x, _box->halfSize.y, _box->halfSize.z);
	boxPoints[2] = _box->body->getPosition() + cyclone::Vector3(_box->halfSize.x, -_box->halfSize.y, _box->halfSize.z);
	boxPoints[3] = _box->body->getPosition() + cyclone::Vector3(-_box->halfSize.x, -_box->halfSize.y, _box->halfSize.z);
	boxPoints[4] = _box->body->getPosition() + cyclone::Vector3(_box->halfSize.x, _box->halfSize.y, -_box->halfSize.z);
	boxPoints[5] = _box->body->getPosition() + cyclone::Vector3(-_box->halfSize.x, _box->halfSize.y, -_box->halfSize.z);
	boxPoints[6] = _box->body->getPosition() + cyclone::Vector3(_box->halfSize.x, -_box->halfSize.y, -_box->halfSize.z);
	boxPoints[7] = _box->body->getPosition() - _box->halfSize;

	for (int i = 0; i < 8;i++)
	{
		cyclone::Vector3 delta = boxPoints[i] - _sphere->body->getPosition();
		cyclone::real distance = delta.magnitude();
		if (distance <= _sphere->radius)
			return true;
	}
	return false;
}

bool PhysicsWorld::BoxBoxCol(cyclone::CollisionBox*, cyclone::CollisionBox*)
{

	return false;
}

bool PhysicsWorld::SpherePlaneCol(cyclone::CollisionSphere* _sphere, cyclone::CollisionPlane _plane)
{
	return false;
}

bool PhysicsWorld::BoxPlaneCol(cyclone::CollisionBox* _box, cyclone::CollisionPlane _plane)
{
	return false;
}
