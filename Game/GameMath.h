/**
 * @file   GameMath.h
 *
 * @brief  �Q�[�����w�֘A�̃w�b�_�t�@�C��
 *
 * @author ����Җ�
 *
 * @date   ���t
 */

 // ���d�C���N���[�h�̖h�~ =====================================================
#pragma once




// �w�b�_�t�@�C���̓ǂݍ��� ===================================================
#include <cmath>




// �萔�̒�` =================================================================




// �\���̂̒�` ===============================================================
/**
 * @brief 2�����x�N�g��
 */
struct Vector2D
{
	float x;    ///< X����
	float y;    ///< Y����
};




// �C�����C���֐��̒�` =======================================================
/**
 * @brief 2D�x�N�g���̉��Z
 *
 * @param[in] v1 ���Z���鍶�ӂ̃x�N�g��
 * @param[in] v2 ���Z����E�ӂ̃x�N�g��
 *
 * @return ���Z���ʂ̃x�N�g��
 */
inline Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D{ (v1.x + v2.x), (v1.y + v2.y) };
}



/**
 * @brief 2D�x�N�g���̌��Z
 *
 * @param[in] v1 ���Z����鍶�ӂ̃x�N�g��
 * @param[in] v2 ���Z����E�ӂ̃x�N�g��
 *
 * @return ���Z���ʂ̃x�N�g��
 */
inline Vector2D operator-(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D{ (v1.x - v2.x), (v1.y - v2.y) };
}



/**
 * @brief 2D�x�N�g���̃X�J���[��Z
 *
 * @param[in] v ���̓x�N�g��
 * @param[in] k ��Z����X�J���[�l
 *
 * @return ���Z���ʂ̃x�N�g��
 */
inline Vector2D operator*(const Vector2D& v, float k)
{
	return Vector2D{ (v.x * k), (v.y * k) };
}



/**
 * @brief 2D�x�N�g���̃X�J���[��Z
 *
 * @param[in] k ��Z����X�J���[�l
 * @param[in] v ���̓x�N�g��
 *
 * @return ���Z���ʂ̃x�N�g��
 */
inline Vector2D operator*(float k, const Vector2D& v)
{
	return v * k;
}



/**
 * @brief 2D�x�N�g���̃X�J���[���Z
 *
 * @param[in] v ���̓x�N�g��
 * @param[in] k ���Z����X�J���[�l
 *
 * @return ���Z���ʂ̃x�N�g��
 */
inline Vector2D operator/(const Vector2D& v, float k)
{
	return Vector2D{ (v.x / k), (v.y / k) };
}



/**
 * @brief 2D�x�N�g���̉��Z���
 *
 * @param[in] v1 ���ʂ������鍶�Ӄx�N�g��
 * @param[in] v2 ���Z����E�Ӄx�N�g��
 *
 * @return �����̍��Ӄx�N�g��
 */
inline Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;

	return v1;
}



/**
 * @brief 2D�x�N�g���̌��Z���
 *
 * @param[in] v1 ���ʂ������鍶�Ӄx�N�g��
 * @param[in] v2 ���Z����E�ӂ̃x�N�g��
 *
 * @return �����̍��Ӄx�N�g��
 */
inline Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;

	return v1;
}



/**
 * @brief 2D�x�N�g���̃X�J���[��Z���
 *
 * @param[in] v ���ʂ������鍶�Ӄx�N�g��
 * @param[in] k ��Z����X�J���[�l
 *
 * @return �����̍��Ӄx�N�g��
 */
inline Vector2D& operator*=(Vector2D& v, float k)
{
	v.x *= k;
	v.y *= k;

	return v;
}



/**
 * @brief 2D�x�N�g���̃X�J���[���Z���
 *
 * @param[in] v ���ʂ������鍶�Ӄx�N�g��
 * @param[in] k ���Z����X�J���[�l
 *
 * @return �����̍��Ӄx�N�g��
 */
inline Vector2D& operator/=(Vector2D& v, float k)
{
	v.x /= k;
	v.y /= k;

	return v;
}



/**
 * @brief 2D�x�N�g�����m�̓���(�h�b�g��)
 *
 * @param[in] v1 ����̃x�N�g��
 * @param[in] v2 ��������̃x�N�g��
 *
 * @return ����(�X�J���[�l)
 */
inline float Dot(const Vector2D& v1, const Vector2D& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}



/**
 * @brief 2D�x�N�g�����m�̊O�ρi�X�J���[�l�j
 *
 * @param[in] v1 ����̃x�N�g��
 * @param[in] v2 ��������̃x�N�g��
 *
 * @return �O��(�X�J���[�l)
 */
inline float Cross(const Vector2D& v1, const Vector2D& v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}



/**
 * @brief 2D�x�N�g���̒���
 *
 * @param[in] v ���̓x�N�g��
 *
 * @return �x�N�g���̒���
 */
inline float Length(const Vector2D& v)
{
	return std::sqrt((v.x * v.x) + (v.y * v.y));
}



/**
 * @brief 2D�x�N�g���̐��K��
 *
 * @param[in] v ���̓x�N�g��
 *
 * @return ���K�����ꂽ�P�ʃx�N�g���B����0�Ȃ�(0,0)��Ԃ�
 */
inline Vector2D Normalize(const Vector2D& v)
{
	constexpr float EPSILON = 1e-5f;    // 0.00001

	float length = Length(v);
	if (length < EPSILON)
	{
		return Vector2D{ 0.0f, 0.0f };
	}

	return v / length;
}



/**
 * @brief [���W�A��] ���� [�x] �ւ̒P�ʕϊ�
 *
 * @param[in] radians �p�x[���W�A��]
 *
 * @return �ϊ���̊p�x[�x]
 */
inline constexpr float ToDegrees(float radians)
{
	return radians * (180.0f / DX_PI_F);
}



/**
 * @brief [�x] ���� [���W�A��] �ւ̒P�ʕϊ�
 *
 * @param[in] degrees �p�x[�x]
 *
 * @return �ϊ���̊p�x[���W�A��]
 */
inline constexpr float ToRadians(float degrees)
{
	return degrees * (DX_PI_F / 180.0f);
}



/**
 * @brief �p�x��-�΁`�΂ɐ��K��
 *
 * @param[in] radians �p�x[���W�A��]
 *
 * @return ���K����̊p�x[���W�A��]
 */
inline float NormalizeAnglePI(float radians)
{
	return std::atan2(std::sin(radians), std::cos(radians));
}



/**
 * @brief �p�x��0�`2�΂ɐ��K��
 *
 * @param[in] radians �p�x[���W�A��]
 *
 * @return ���K����̊p�x[���W�A��]
 */
inline float NormalizeAngle2PI(float radians)
{
	float angle = NormalizeAnglePI(radians);
	if (angle < 0.0f)
	{
		angle += DX_TWO_PI_F;
	}

	return angle;
}
