#pragma once


class PointOfImpact
{
private:

	// 着弾のアニメーションステート
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, Anim02, Anim03, Anim04,
	};


	// 定数宣言
private:

	// 着弾アニメーションの感覚
	static constexpr int ANIMATION_INTERVAL = 4;

	// 着弾エフェクトのサイズ
	static constexpr int SIZE = 32;

	// 爆発のスプライトシート上のグラフィックの位置
	static constexpr POINT POINT_OF_IMPACT[] =
	{
		{ 0 + 16 * 0, 152 },		// パターン１
		{ 0 + 16 * 1, 152 },		// パターン２
		{ 0 + 16 * 2, 152 },		// パターン３
		{ 0 + 16 * 3, 152 },		// パターン４
	};


	// データメンバの宣言
private:

	// 表示位置
	


public:

	// コンストラクタ
	PointOfImpact();

	// デストラクタ
	~PointOfImpact();


private:

};