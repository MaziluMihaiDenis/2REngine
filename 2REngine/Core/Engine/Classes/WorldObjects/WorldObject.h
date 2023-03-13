#pragma once

#include "EmptyWorldObject.h"
#include "../../../Types/Transformation2D.h"

class WorldObject : public EmptyWorldObject
{
private:
	Transformation2D transformation;

public:
	void SetPosition(Vector2D &translation);
	void SetSize(Vector2D &scale);
	void SetRotation(float rotation);

	void SetRelativePosition(Vector2D& translation);
	void SetRelativeSize(Vector2D& scale);
	void SetRelativeRotation(float rotation);

	Vector2D GetPosition() const;
	Vector2D GetSize() const;
	float GetRotation() const;

	Vector2D GetRelativePosition() const;
	Vector2D GetRelativeSize() const;
	float GetRelativeRotation() const;
};

