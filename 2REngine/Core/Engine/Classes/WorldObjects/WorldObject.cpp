#include "WorldObject.h"

void WorldObject::SetPosition(Vector2D& translation)
{
	transformation.RelativePosition = transformation.Position = translation;

	if (WorldObject* parent = GetParent<WorldObject>())
		transformation.RelativePosition = parent->GetPosition() - translation;


	for (EmptyWorldObject* child : GetChildren())
		if (WorldObject* wObj = (WorldObject*)child)
			wObj->SetPosition(translation + wObj->GetRelativePosition());
}

void WorldObject::SetSize(Vector2D& scale)
{
	transformation.RelativeSize = transformation.Size = scale;

	if (WorldObject* parent = GetParent<WorldObject>())
		transformation.RelativeSize = parent->GetSize() - scale;

	for (EmptyWorldObject* child : GetChildren())
		if (WorldObject* wObj = (WorldObject*)child)
			wObj->SetSize(scale + wObj->GetRelativeSize());
}

void WorldObject::SetRotation(float rotation)
{
	transformation.RelativeRotation = transformation.Rotation = rotation;

	if (WorldObject* parent = GetParent<WorldObject>())
		transformation.RelativeRotation = parent->GetRotation() - rotation;

	for (EmptyWorldObject* child : GetChildren())
		if (WorldObject* wObj = (WorldObject*)child)
			wObj->SetRotation(rotation + wObj->GetRelativeRotation());
}

void WorldObject::SetRelativePosition(Vector2D& translation)
{
	// TO DO
}

void WorldObject::SetRelativeSize(Vector2D& scale)
{
	// TO DO
}

void WorldObject::SetRelativeRotation(float rotation)
{
	// TO DO
}

Vector2D WorldObject::GetPosition() const
{
	return transformation.Position;
}

Vector2D WorldObject::GetSize() const
{
	return transformation.Size;
}

float WorldObject::GetRotation() const
{
	return transformation.Rotation;
}

Vector2D WorldObject::GetRelativePosition() const
{
	return transformation.RelativePosition;
}

Vector2D WorldObject::GetRelativeSize() const
{
	return transformation.RelativeSize;
}

float WorldObject::GetRelativeRotation() const
{
	return transformation.RelativeRotation;
}
