#pragma once

#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>

namespace dl
{
	template<typename T>
	class MathTemplate
	{
	public:
		static const float PI;

		static T getLeanthVector(Vector2D<T>& vctr);
		static T getLeanthVector(Vector2D<T> vctr);

		static T getScalarMull(Vector2D<T>& vctr_a, Vector2D<T>& vctr_b);
		static T getScalarMull(Vector2D<T> vctr_a, Vector2D<T> vctr_b);

		static T getCosVectors(Vector2D<T>& vctr_a, Vector2D<T>& vctr_b);
		static T getCosVectors(Vector2D<T> vctr_a, Vector2D<T> vctr_b);

		static void normalVector(Vector2D<T>& vctr);
		static Vector2D<T> normalVector(Vector2D<T> vctr);

		static Vector2D<T> projectionVectors(Vector2D<T>& projectionVector, Vector2D<T>& onProjectionVector);
		static Vector2D<T> projectionVectors(Vector2D<T> projectionVector, Vector2D<T> onProjectionVector);
	private:

	};

	typedef MathTemplate<int> MathInt;
	typedef MathTemplate<float> MathFlaot;

	template<typename T>
	inline T MathTemplate<T>::getLeanthVector(Vector2D<T>& vctr)
	{
		return std::sqrtf(std::powf(vctr.x, 2) + std::powf(vctr.y, 2));
	}
	template<typename T>
	inline T MathTemplate<T>::getLeanthVector(Vector2D<T> vctr)
	{
		return MathTemplate<T>::getLeanthVector(vctr);
	}
	template<typename T>
	inline T MathTemplate<T>::getScalarMull(Vector2D<T>& vctr_a, Vector2D<T>& vctr_b)
	{
		return vctr_a.x * vctr_b.x + vctr_a.y * vctr_b.y;
	}
	template<typename T>
	inline T MathTemplate<T>::getScalarMull(Vector2D<T> vctr_a, Vector2D<T> vctr_b)
	{
		return MathTemplate<T>::getScalarMull(vctr_a, vctr_b);
	}
	template<typename T>
	inline T MathTemplate<T>::getCosVectors(Vector2D<T>& vctr_a, Vector2D<T>& vctr_b)
	{
		return (MathTemplate<T>::getScalarMull(vctr_a, vctr_b)) /
			(MathTemplate<T>::getLeanthVector(vctr_a) * MathTemplate<T>::getLeanthVector(vctr_b));
	}
	template<typename T>
	inline T MathTemplate<T>::getCosVectors(Vector2D<T> vctr_a, Vector2D<T> vctr_b)
	{
		return MathTemplate<T>::getCosVectors(vctr_a, vctr_b);
	}
	template<typename T>
	inline void MathTemplate<T>::normalVector(Vector2D<T>& vctr)
	{
		vctr /= MathTemplate<T>::getLeanthVector(vctr);
	}
	template<typename T>
	inline Vector2D<T> MathTemplate<T>::normalVector(Vector2D<T> vctr)
	{
		MathTemplate<T>::normalVector(vctr);
		return vctr;
	}
	template<typename T>
	inline Vector2D<T> MathTemplate<T>::projectionVectors(Vector2D<T>& projectionVector, Vector2D<T>& onProjectionVector)
	{
		MathTemplate<T>::normalVector(onProjectionVector);
		return (onProjectionVector * projectionVector) * onProjectionVector;

	}
	template<typename T>
	inline Vector2D<T> MathTemplate<T>::projectionVectors(Vector2D<T> projectionVector, Vector2D<T> onProjectionVector)
	{
		return MathTemplate<T>::projectionVectors(projectionVector, onProjectionVector);
	}
}