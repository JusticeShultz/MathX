#include "Matrix3.h"
#include "Vector2.h"

namespace MathX
{
	#pragma region M3
	Matrix3::Matrix3() {}
	Matrix3::Matrix3(const Matrix3& z)
	{
		for(int i = 0; i < 9; ++i)
			this->m[i] = z.m[i];
	}
	Matrix3::Matrix3(float *ptr)
	{
		for (int i = 0; i < 9; i++)
			m[i] = ptr[i];
	}
	Matrix3::Matrix3(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
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
	}
	Matrix3::~Matrix3() {}

	void Matrix3::Print() const
	{
		std::cout << "(";
		for (int i = 0; i < 9; ++i)
			std::cout << m[i] << ", ";
		std::cout << ")";
	}
	Matrix3 Matrix3::GetIdentity()
	{
		Matrix3 temp;

		temp.m[0] = 1;
		temp.m[3] = 0;
		temp.m[6] = 0;

		temp.m[1] = 0;
		temp.m[4] = 1;
		temp.m[7] = 0;

		temp.m[2] = 0;
		temp.m[5] = 0;
		temp.m[8] = 1;

		return temp;
	}
	void Matrix3::SetIdentity()
	{
		Matrix3 temp;

		m[0] = 1;
		m[3] = 0;
		m[6] = 0;

		m[1] = 0;
		m[4] = 1;
		m[7] = 0;

		m[2] = 0;
		m[5] = 0;
		m[8] = 1;
	}
	void Matrix3::Translate(float x, float y)
	{
		Matrix3 tempMatrix = GetIdentity();
		tempMatrix.zAxis.X = x;
		tempMatrix.zAxis.Y = y;

		for (int i = 0; i < 9; ++i)
		{
			m[i] = tempMatrix.m[i];
		}
	}
	void Matrix3::Translate(const Vector2 &v)
	{
		this->Translate(v.X, v.Y);
	}
	Matrix3 Matrix3::GetTranslation(float x, float y)
	{
		Matrix3 temp = *this;
		temp.Translate(x, y);
		return temp;
	}
	Matrix3 Matrix3::GetTranslation(const Vector2 &v)
	{
		return this->GetTranslation(v.X, v.Y);
	}
	void Matrix3::SetRotateX(float rot)
	{
		m[0] = 1;
		m[3] = 0;
		m[6] = 0;

		m[1] = 0;
		m[4] = std::cos(rot);
		m[7] = std::sin(rot);

		m[2] = 0;
		m[5] = std::sin(rot) * -1;
		m[8] = std::cos(rot);
	}
	void Matrix3::SetRotateY(float rot)
	{
		m[0] = std::cos(rot);
		m[3] = 0;
		m[6] = std::sin(rot) * -1;

		m[1] = 0;
		m[4] = 1;
		m[7] = 0;

		m[2] = std::sin(rot);
		m[5] = 0;
		m[8] = std::cos(rot);
	}
	void Matrix3::SetRotateZ(float rot)
	{
		m[0] = std::cos(rot);
		m[3] = std::sin(rot) * -1;
		m[6] = 0;

		m[1] = std::sin(rot);
		m[4] = std::cos(rot);
		m[7] = 0;

		m[2] = 0;
		m[5] = 0;
		m[8] = 1;
	}
	Matrix3 Matrix3::GetRotation(float rot)
	{
		Matrix3 temp = *this;
		temp.SetRotateZ(rot);
		return temp;
	}
	Matrix3 Matrix3::GetScale(float xScale, float yScale)
	{
		Matrix3 temp = { 0,0,0,0,0,0,0,0,0 };
		temp = temp.GetIdentity();
		temp.xAxis.X = xScale;
		temp.yAxis.Y = yScale;
		//temp.Scale(xScale, yScale);
		return temp;
	}
	void Matrix3::Scale(float xScale, float yScale)
	{
		Matrix3 tempMatrix = GetIdentity();
		tempMatrix.xAxis.X = xScale;
		tempMatrix.yAxis.Y = yScale;
		
		for (int i = 0; i < 9; ++i)
		{
			m[i] = tempMatrix.m[i];
		}
	}
	void Matrix3::Set(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
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
	}
	void Matrix3::Set(float *ptr)
	{
		for (int i = 0; i < 9; i++)
			m[i] = ptr[i];
	}
	void Matrix3::Transpose()
	{
		m[0] = m[0];
		m[1] = m[3];
		m[2] = m[6];
		m[3] = m[1];
		m[4] = m[4];
		m[5] = m[7];
		m[6] = m[2];
		m[7] = m[5];
		m[8] = m[8];
	}
	Matrix3 Matrix3::GetTranspose() const
	{
		Matrix3 temp = *this;
		temp.Transpose();
		return temp;
	}

	#pragma endregion Matrix3
}

/*
	036
	147
	258
*/