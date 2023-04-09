#pragma once

#include <Engine/Classes/WorldObject.h>

enum SHAPE
{
	CIRCLE,
	RECTANGLE
};

struct CollisionShape2D
{
	friend class Physics;

public:

public:
	struct Extent
	{
		Vector2D Size;
		Vector2D ReferencePoint;
	} extent;

public:
	bool layer[16]
	{
		1, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
	bool mask[16]
	{
		1, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};

protected:
	virtual void OnCollisionEnter(WorldObject* hit);
	virtual void OnTriggerEnter(WorldObject* hit);
	virtual void OnCollisionExit(WorldObject* hit);
	virtual void OnTriggerExit(WorldObject* hit);
protected:
	void SetReferencePoint(Vector2D& point);
};