#include "Matrix4.h"

namespace MathX
{
	#pragma region M4
	Matrix4::Matrix4() {}
	Matrix4::Matrix4(const Matrix4& z)
	{
		*this->m = *z.m;
	}
	Matrix4::Matrix4(float *ptr)
	{
		for (int i = 0; i < 9; i++)
			m[i] = ptr[i];
	}
	Matrix4::Matrix4(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8,
		float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16)
	{
		m[0] = a1;
		m[1] = a2;
		m[2] = a3;
		m[3] = a4;
		m[4] = a5;
		m[5] = a6;
		m[6] = a7;
		m[7] = a8;
		m[8] = a9;
		m[9] = a10;
		m[10] = a11;
		m[11] = a12;
		m[12] = a13;
		m[13] = a14;
		m[14] = a15;
		m[15] = a16;
	}
	Matrix4::~Matrix4() {}

	void Matrix4::Print() const
	{
		std::cout << "(";
		for (int i = 0; i < 16; ++i)
			std::cout << m[i] << ", ";
		std::cout << ")";
	}
	Matrix4 Matrix4::GetIdentity()
	{
		Matrix4 temp;

		temp.m[0] = 1;
		temp.m[4] = 0;
		temp.m[8] = 0;
		temp.m[12] = 0;

		temp.m[1] = 0;
		temp.m[5] = 1;
		temp.m[9] = 0;
		temp.m[13] = 0;

		temp.m[2] = 0;
		temp.m[6] = 0;
		temp.m[10] = 1;
		temp.m[14] = 0;

		temp.m[3] = 0;
		temp.m[7] = 0;
		temp.m[11] = 0;
		temp.m[15] = 1;

		return temp;
	}
	void Matrix4::SetIdentity()
	{
		m[0] = 1;
		m[4] = 0;
		m[8] = 0;
		m[12] = 0;

		m[1] = 0;
		m[5] = 1;
		m[9] = 0;
		m[13] = 0;

		m[2] = 0;
		m[6] = 0;
		m[10] = 1;
		m[14] = 0;

		m[3] = 0;
		m[7] = 0;
		m[11] = 0;
		m[15] = 1;
	}
	void Matrix4::Translate(float x, float y, float z)
	{
		m[0] += x;
		m[1] += x;
		m[2] += x;
		m[3] += x;

		m[4] += y;
		m[5] += y;
		m[6] += y;
		m[7] += y;

		m[8] += z;
		m[9] += z;
		m[10] += z;
		m[11] += z;
	}
	void Matrix4::Translate(const Vector3 &v)
	{
		this->Translate(v.X, v.Y, v.Z);
	}
	Matrix4 Matrix4::GetTranslation(float x, float y, float z)
	{
		Matrix4 temp = *this;
		temp.Translate(x, y, z);
		return temp;
	}
	Matrix4 Matrix4::GetTranslation(const Vector3 &v)
	{
		return this->GetTranslation(v.X, v.Y, v.Z);
	}
	void Matrix4::SetRotateX(float rot)
	{
		m[0] = 1;
		m[4] = 0;
		m[8] = 0;

		m[1] = 0;
		m[5] = std::cos(rot);
		m[9] = std::sin(rot);

		m[2] = 0;
		m[6] = std::sin(rot) * -1;
		m[10] = std::cos(rot);
	}
	void Matrix4::SetRotateY(float rot)
	{
		m[0] = std::cos(rot);
		m[4] = 0;
		m[8] = std::sin(rot) * -1;

		m[1] = 0;
		m[5] = 1;
		m[9] = 0;

		m[2] = std::sin(rot);
		m[6] = 0;
		m[10] = std::cos(rot);
	}
	void Matrix4::SetRotateZ(float rot)
	{
		m[0] = std::cos(rot); m[4] = std::sin(rot) * -1; m[8] = 0;  m[12] = 0;
		m[1] = std::sin(rot); m[5] = std::cos(rot);		 m[9] = 0;  m[13] = 0;
		m[2] = 0;			  m[6] = 0;					 m[10] = 1; m[14] = 0;
		m[3] = 0;			  m[7] = 0;				     m[11] = 0; m[15] = 1;
	}
	Matrix4 Matrix4::GetRotation(float rot)
	{
		Matrix4 temp = *this;
		//temp.Rotate(rot);
		return temp;
	}
	Matrix4 Matrix4::GetScale(float xScale, float yScale, float zScale)
	{
		Matrix4 temp = *this;
		temp.Scale(xScale, yScale, zScale);
		return temp;
	}
	void Matrix4::Scale(float xScale, float yScale, float zScale)
	{
		m[0] *= xScale;
		m[1] *= xScale;
		m[2] *= xScale;
		m[3] *= xScale;
		m[4] *= yScale;
		m[5] *= yScale;
		m[6] *= yScale;
		m[7] *= yScale;
		m[8] *= zScale;
		m[9] *= zScale;
		m[10] *= zScale;
		m[11] *= zScale;
	}
	void Matrix4::Set(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8,
		float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16)
	{
		m[0] = a1;
		m[1] = a2;
		m[2] = a3;
		m[3] = a4;
		m[4] = a5;
		m[5] = a6;
		m[6] = a7;
		m[7] = a8;
		m[8] = a9;
		m[9] = a10;
		m[10] = a11;
		m[11] = a12;
		m[12] = a13;
		m[13] = a14;
		m[14] = a15;
		m[15] = a16;
	}
	void Matrix4::Set(float *ptr)
	{
		for (int i = 0; i < 16; i++)
			m[i] = ptr[i];
	}
	void Matrix4::Transpose()
	{
		m[0] = m[0];
		m[4] = m[1];
		m[8] = m[2];
		m[12] = m[3];

		m[1] = m[4];
		m[5] = m[5];
		m[9] = m[6];
		m[13] = m[7];

		m[2] = m[8];
		m[6] = m[9];
		m[10] = m[10];
		m[14] = m[11];

		m[3] = m[12];
		m[7] = m[13];
		m[11] = m[14];
		m[15] = m[15];
	}
	Matrix4 Matrix4::GetTranspose() const
	{
		Matrix4 temp = *this;
		temp.Transpose();
		return temp;
	}
	#pragma endregion Matrix4
}