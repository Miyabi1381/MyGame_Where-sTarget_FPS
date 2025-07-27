#pragma once


class PointOfImpact
{
private:

	// 着弾のアニメーションステート
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, 
		Anim02, 
		Anim03, 
		Anim04,
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
	POINT m_position;

	// アニメーションステート
	AnimationState m_animationState;

	// 着弾アニメーションカウンター
	int m_animationCounter;


public:

	// コンストラクタ
	PointOfImpact();

	// 更新処理
	void Update();

	// 描画処理
	void Render(int ghWheresTarget);

	// 指定した位置に着弾エフェクトを表示する関数
	void OnHit(POINT position);

};