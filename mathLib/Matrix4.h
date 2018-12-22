#pragma once
#include "utils.h"
#include "Vector3.h"
#include "Vector4.h"

namespace MathX
{
	class Matrix4
	{
	public:
		union
		{
			struct
			{
				Vector4 xAxis;
				Vector4 yAxis;
				Vector4 zAxis;
				Vector4 wAxis;
			};

			struct
			{
				float m1, m2, m3, m4,
					m5, m6, m7, m8,
					m9, m10, m11, m12,
					m13, m14, m15, m16;
			};

			Vector4 axis[4];
			float m[16];
			float mm[4][4];
		};

		Matrix4();
		Matrix4(const Matrix4& z);
		Matrix4(float *ptr);
		Matrix4(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8,
			float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16);
		~Matrix4();

		void Print() const;
		Matrix4 GetIdentity();
		void SetIdentity();
		Matrix4 GetTranslation(float x, float y, float z);
		Matrix4 GetTranslation(const Vector3 &v);
		void Translate(float x, float y, float z);
		void Translate(const Vector3 &v);
		void SetRotateX(float rot);
		void SetRotateY(float rot);
		void SetRotateZ(float rot);
		Matrix4 GetRotation(float rot);
		Matrix4 GetScale(float xScale, float yScale, float zScale);
		void Scale(float xScale, float yScale, float zScale);
		//Rebuild the matrix
		void Set(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8,
			float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16);
		//Rebuild the matrix - expects pointer to array of 9 floats
		void Set(float *ptr);
		void Transpose();
		Matrix4 GetTranspose() const;

		#pragma region Operators
		Matrix4 operator + (const Matrix4 &rhs)
		{
			Matrix4 tempMatrix = *this;

			for (int i = 0; i < 16; i++)
			{
				tempMatrix.m[i] += rhs.m[i];
			}

			return tempMatrix;
		}
		Matrix4 operator + (const float &rhs)
		{
			Matrix4 tempMatrix = *this;

			for (int i = 0; i < 16; i++)
			{
				tempMatrix.m[i] += rhs;
			}


			return tempMatrix;
		}
		Matrix4 operator += (const Matrix4 &rhs)
		{
			(*this) = (*this) + rhs;
			return (*this);
		}
		Matrix4 operator += (const float &rhs)
		{
			(*this) = (*this) + rhs;
			return (*this);
		}
		Matrix4 operator - (const Matrix4 &rhs)
		{
			Matrix4 tempMatrix = *this;

			for (int i = 0; i < 16; i++)
			{

				tempMatrix.m[i] -= rhs.m[i];

			}

			return tempMatrix;
		}
		Matrix4 operator - (const float &rhs)
		{
			Matrix4 tempMatrix = *this;

			for (int i = 0; i < 16; i++)
			{
				tempMatrix.m[i] -= rhs;
			}

			return tempMatrix;
		}
		Matrix4 operator -= (const Matrix4 &rhs)
		{
			(*this) = (*this) - rhs;
			return (*this);
		}
		Matrix4 operator -= (const float &rhs)
		{
			(*this) = (*this) - rhs;
			return (*this);
		}
		Matrix4	operator * (const Matrix4 &rhs)
		{
			Matrix4 a;
			float sum;

			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					sum = 0;

					for (int k = 0; k < 4; ++k)
						sum += mm[k][i] * rhs.mm[j][k];

					a.mm[j][i] = sum;
				}

			return a;
		}
		Matrix4	operator * (const float &rhs)
		{
			Matrix4 tempMatrix = *this;

			for (int i = 0; i < 16; i++)
				tempMatrix.m[i] *= rhs;

			return tempMatrix;
		}
		Matrix4& operator = (const Matrix4 &rhs)
		{
			if (this == &rhs)
				return *this;

			for (int i = 0; i < 16; i++)
				m[i] = rhs.m[i];

			return *this;
		}
		Matrix4 operator = (const float rhs[16])
		{
			if (this->m == rhs)
				return *this;

			for (int i = 0; i < 16; i++)
				m[i] = rhs[i];

			return *this;
		}
		Matrix4 operator *= (const Matrix4 &rhs)
		{
			(*this) = (*this) * rhs;
			return (*this);
		}
		Matrix4 operator *= (const float &rhs)
		{
			(*this) = (*this) * rhs;
			return (*this);
		}
		bool operator != (const Matrix4 &rhs)
		{
			for (int i = 0; i < 16; i++)
				if (m[i] != rhs.m[i])
					return true;

			return false;
		}
		bool operator == (const Matrix4 &rhs) const
		{
			bool check[16];

			Matrix4 temp1 = rhs;
			Matrix4 temp2 = Matrix4(*this);

			for (int i = 0; i < 16; ++i)
			{
				//Calculates the difference.
				float diff1 = fabs(temp1.m[i] - temp2.m[i]);
				temp1.m[i] = fabs(temp1.m[i]);
				temp2.m[i] = fabs(temp2.m[i]);

				//Finds the largest of the 2 values.
				float largest1 = (temp2.m[i] > temp1.m[i]) ? temp2.m[i] : temp1.m[i];

				if (diff1 <= largest1 * FLOATMIN)
					check[i] = true;
				else check[i] = false;
			}

			bool result = false;
			for (int i = 0; i < 16; ++i) if (check[i]) result = true;
			return result;
		}

		Matrix4 operator + (const Vector3 &rhs)
		{
			Matrix4 tempMatrix = *this;

			tempMatrix.m[0] += rhs.X;
			tempMatrix.m[1] += rhs.X;
			tempMatrix.m[2] += rhs.X;
			tempMatrix.m[3] += rhs.X;

			tempMatrix.m[4] += rhs.Y;
			tempMatrix.m[5] += rhs.Y;
			tempMatrix.m[6] += rhs.Y;
			tempMatrix.m[7] += rhs.Y;

			tempMatrix.m[8] += rhs.Z;
			tempMatrix.m[9] += rhs.Z;
			tempMatrix.m[10] += rhs.Z;
			tempMatrix.m[11] += rhs.Z;

			return tempMatrix;
		}
		Matrix4 operator += (const Vector3 &rhs)
		{
			(*this) = (*this) + rhs;
			return (*this);
		}
		Matrix4 operator - (const Vector3 &rhs)
		{
			Matrix4 tempMatrix = *this;

			tempMatrix.m[0] -= rhs.X;
			tempMatrix.m[1] -= rhs.X;
			tempMatrix.m[2] -= rhs.X;
			tempMatrix.m[3] -= rhs.X;

			tempMatrix.m[4] -= rhs.Y;
			tempMatrix.m[5] -= rhs.Y;
			tempMatrix.m[6] -= rhs.Y;
			tempMatrix.m[7] -= rhs.Y;

			tempMatrix.m[8] -= rhs.Z;
			tempMatrix.m[9] -= rhs.Z;
			tempMatrix.m[10] -= rhs.Z;
			tempMatrix.m[11] -= rhs.Z;

			return tempMatrix;
		}
		Matrix4 operator -= (const Vector3 &rhs)
		{
			(*this) = (*this) - rhs;
			return (*this);
		}
		Vector3	operator * (const Vector3 &rhs)
		{
			Vector4 vec1(m[0], m[4], m[8], m[12]);
			Vector4 vec2(m[1], m[5], m[9], m[13]);
			Vector4 vec3(m[2], m[6], m[10], m[14]);
			Vector4 vec4(m[3], m[7], m[11], m[15]);

			Vector4 pain(rhs.X, rhs.Y, rhs.Z, 0);
			return Vector3(vec1.Dot(pain), vec2.Dot(pain), vec3.Dot(pain));
		}

		Matrix4 operator = (const Vector3 &rhs)
		{
			Matrix4 tempMatrix = *this;

			tempMatrix.m[0] = rhs.X;
			tempMatrix.m[1] = rhs.X;
			tempMatrix.m[2] = rhs.X;
			tempMatrix.m[3] = rhs.X;

			tempMatrix.m[4] = rhs.Y;
			tempMatrix.m[5] = rhs.Y;
			tempMatrix.m[6] = rhs.Y;
			tempMatrix.m[7] = rhs.Y;

			tempMatrix.m[8] = rhs.Z;
			tempMatrix.m[9] = rhs.Z;
			tempMatrix.m[10] = rhs.Z;
			tempMatrix.m[11] = rhs.Z;

			tempMatrix.m[12] = 0;
			tempMatrix.m[13] = 0;
			tempMatrix.m[14] = 0;
			tempMatrix.m[15] = 0;

			return tempMatrix;
		}
		Matrix4 operator *= (const Vector3 &rhs)
		{
			(*this) = (*this) * rhs;
			return (*this);
		}

		Matrix4 operator + (const Vector4 &rhs)
		{
			Matrix4 tempMatrix = *this;

			tempMatrix.m[0] += rhs.X;
			tempMatrix.m[1] += rhs.X;
			tempMatrix.m[2] += rhs.X;
			tempMatrix.m[3] += rhs.X;

			tempMatrix.m[4] += rhs.Y;
			tempMatrix.m[5] += rhs.Y;
			tempMatrix.m[6] += rhs.Y;
			tempMatrix.m[7] += rhs.Y;

			tempMatrix.m[8] += rhs.Z;
			tempMatrix.m[9] += rhs.Z;
			tempMatrix.m[10] += rhs.Z;
			tempMatrix.m[11] += rhs.Z;

			tempMatrix.m[12] += rhs.W;
			tempMatrix.m[13] += rhs.W;
			tempMatrix.m[14] += rhs.W;
			tempMatrix.m[15] += rhs.W;

			return tempMatrix;
		}
		Matrix4 operator += (const Vector4 &rhs)
		{
			(*this) = (*this) + rhs;
			return (*this);
		}
		Matrix4 operator - (const Vector4 &rhs)
		{
			Matrix4 tempMatrix = *this;

			tempMatrix.m[0] -= rhs.X;
			tempMatrix.m[1] -= rhs.X;
			tempMatrix.m[2] -= rhs.X;
			tempMatrix.m[3] -= rhs.X;

			tempMatrix.m[4] -= rhs.Y;
			tempMatrix.m[5] -= rhs.Y;
			tempMatrix.m[6] -= rhs.Y;
			tempMatrix.m[7] -= rhs.Y;

			tempMatrix.m[8] -= rhs.Z;
			tempMatrix.m[9] -= rhs.Z;
			tempMatrix.m[10] -= rhs.Z;
			tempMatrix.m[11] -= rhs.Z;

			tempMatrix.m[12] -= rhs.W;
			tempMatrix.m[13] -= rhs.W;
			tempMatrix.m[14] -= rhs.W;
			tempMatrix.m[15] -= rhs.W;

			return tempMatrix;
		}
		Matrix4 operator -= (const Vector4 &rhs)
		{
			(*this) = (*this) - rhs;
			return (*this);
		}
		Vector4	operator * (const Vector4 &rhs)
		{
			Vector4 vec1(m[0], m[4], m[8], m[12]);
			Vector4 vec2(m[1], m[5], m[9], m[13]);
			Vector4 vec3(m[2], m[6], m[10], m[14]);
			Vector4 vec4(m[3], m[7], m[11], m[15]);

			return Vector4(vec1.Dot(rhs), vec2.Dot(rhs), vec3.Dot(rhs), vec4.Dot(rhs));
		}
		Matrix4 operator = (const Vector4 &rhs)
		{
			Matrix4 tempMatrix = *this;

			tempMatrix.m[0] = rhs.X;
			tempMatrix.m[1] = rhs.X;
			tempMatrix.m[2] = rhs.X;
			tempMatrix.m[3] = rhs.X;

			tempMatrix.m[4] = rhs.Y;
			tempMatrix.m[5] = rhs.Y;
			tempMatrix.m[6] = rhs.Y;
			tempMatrix.m[7] = rhs.Y;

			tempMatrix.m[8] = rhs.Z;
			tempMatrix.m[9] = rhs.Z;
			tempMatrix.m[10] = rhs.Z;
			tempMatrix.m[11] = rhs.Z;

			tempMatrix.m[12] = rhs.W;
			tempMatrix.m[13] = rhs.W;
			tempMatrix.m[14] = rhs.W;
			tempMatrix.m[15] = rhs.W;

			return tempMatrix;
		}
		Matrix4 operator *= (const Vector4 &rhs)
		{
			(*this) = (*this) * rhs;
			return (*this);
		}

	#pragma endregion Matrix4 Operators
	};

	

	inline std::ostream & operator << (std::ostream& stream, const Matrix4 &matrix) { matrix.Print(); return stream; }

	inline std::ostream & operator << (std::ostream& stream, Matrix4 &matrix) { matrix.Print(); return stream; }
	inline std::ostream & operator << (Matrix4 &matrix, std::ostream& stream) { matrix.Print(); return stream; }
}