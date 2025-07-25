/**
 * @file   GameMath.h
 *
 * @brief  ゲーム数学関連のヘッダファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

 // 多重インクルードの防止 =====================================================
#pragma once




// ヘッダファイルの読み込み ===================================================
#include <cmath>




// 定数の定義 =================================================================




// 構造体の定義 ===============================================================
/**
 * @brief 2次元ベクトル
 */
struct Vector2D
{
	float x;    ///< X成分
	float y;    ///< Y成分
};




// インライン関数の定義 =======================================================
/**
 * @brief 2Dベクトルの加算
 *
 * @param[in] v1 加算する左辺のベクトル
 * @param[in] v2 加算する右辺のベクトル
 *
 * @return 演算結果のベクトル
 */
inline Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D{ (v1.x + v2.x), (v1.y + v2.y) };
}



/**
 * @brief 2Dベクトルの減算
 *
 * @param[in] v1 減算される左辺のベクトル
 * @param[in] v2 減算する右辺のベクトル
 *
 * @return 演算結果のベクトル
 */
inline Vector2D operator-(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D{ (v1.x - v2.x), (v1.y - v2.y) };
}



/**
 * @brief 2Dベクトルのスカラー乗算
 *
 * @param[in] v 入力ベクトル
 * @param[in] k 乗算するスカラー値
 *
 * @return 演算結果のベクトル
 */
inline Vector2D operator*(const Vector2D& v, float k)
{
	return Vector2D{ (v.x * k), (v.y * k) };
}



/**
 * @brief 2Dベクトルのスカラー乗算
 *
 * @param[in] k 乗算するスカラー値
 * @param[in] v 入力ベクトル
 *
 * @return 演算結果のベクトル
 */
inline Vector2D operator*(float k, const Vector2D& v)
{
	return v * k;
}



/**
 * @brief 2Dベクトルのスカラー除算
 *
 * @param[in] v 入力ベクトル
 * @param[in] k 除算するスカラー値
 *
 * @return 演算結果のベクトル
 */
inline Vector2D operator/(const Vector2D& v, float k)
{
	return Vector2D{ (v.x / k), (v.y / k) };
}



/**
 * @brief 2Dベクトルの加算代入
 *
 * @param[in] v1 結果を代入する左辺ベクトル
 * @param[in] v2 加算する右辺ベクトル
 *
 * @return 代入後の左辺ベクトル
 */
inline Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;

	return v1;
}



/**
 * @brief 2Dベクトルの減算代入
 *
 * @param[in] v1 結果を代入する左辺ベクトル
 * @param[in] v2 減算する右辺のベクトル
 *
 * @return 代入後の左辺ベクトル
 */
inline Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;

	return v1;
}



/**
 * @brief 2Dベクトルのスカラー乗算代入
 *
 * @param[in] v 結果を代入する左辺ベクトル
 * @param[in] k 乗算するスカラー値
 *
 * @return 代入後の左辺ベクトル
 */
inline Vector2D& operator*=(Vector2D& v, float k)
{
	v.x *= k;
	v.y *= k;

	return v;
}



/**
 * @brief 2Dベクトルのスカラー除算代入
 *
 * @param[in] v 結果を代入する左辺ベクトル
 * @param[in] k 除算するスカラー値
 *
 * @return 代入後の左辺ベクトル
 */
inline Vector2D& operator/=(Vector2D& v, float k)
{
	v.x /= k;
	v.y /= k;

	return v;
}



/**
 * @brief 2Dベクトル同士の内積(ドット積)
 *
 * @param[in] v1 一方のベクトル
 * @param[in] v2 もう一方のベクトル
 *
 * @return 内積(スカラー値)
 */
inline float Dot(const Vector2D& v1, const Vector2D& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}



/**
 * @brief 2Dベクトル同士の外積（スカラー値）
 *
 * @param[in] v1 一方のベクトル
 * @param[in] v2 もう一方のベクトル
 *
 * @return 外積(スカラー値)
 */
inline float Cross(const Vector2D& v1, const Vector2D& v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}



/**
 * @brief 2Dベクトルの長さ
 *
 * @param[in] v 入力ベクトル
 *
 * @return ベクトルの長さ
 */
inline float Length(const Vector2D& v)
{
	return std::sqrt((v.x * v.x) + (v.y * v.y));
}



/**
 * @brief 2Dベクトルの正規化
 *
 * @param[in] v 入力ベクトル
 *
 * @return 正規化された単位ベクトル。長さ0なら(0,0)を返す
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
 * @brief [ラジアン] から [度] への単位変換
 *
 * @param[in] radians 角度[ラジアン]
 *
 * @return 変換後の角度[度]
 */
inline constexpr float ToDegrees(float radians)
{
	return radians * (180.0f / DX_PI_F);
}



/**
 * @brief [度] から [ラジアン] への単位変換
 *
 * @param[in] degrees 角度[度]
 *
 * @return 変換後の角度[ラジアン]
 */
inline constexpr float ToRadians(float degrees)
{
	return degrees * (DX_PI_F / 180.0f);
}



/**
 * @brief 角度を-π～πに正規化
 *
 * @param[in] radians 角度[ラジアン]
 *
 * @return 正規化後の角度[ラジアン]
 */
inline float NormalizeAnglePI(float radians)
{
	return std::atan2(std::sin(radians), std::cos(radians));
}



/**
 * @brief 角度を0～2πに正規化
 *
 * @param[in] radians 角度[ラジアン]
 *
 * @return 正規化後の角度[ラジアン]
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
