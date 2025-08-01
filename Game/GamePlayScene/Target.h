#pragma once
#include "Game/GameMath.h"


// 敵クラス
class Target
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 縦幅と横幅
	static constexpr int SIZE = 64;

	// 移動の速さ
	static constexpr int SPEED = 2;


	// データメンバの宣言 -----------------------------------------------
private:

	// アクティブならtrueを設定
	bool m_isActive;

	// 位置
	Vector2D m_position;

	// 速度
	Vector2D m_velocity;

	// 向き(Rad)
	float m_angle;


	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Target();

	// デストラクタ
	~Target();

	// 初期化関数
	void Initialize(Vector2D position);

	// 更新関数
	void Update();

	// 描画関数
	void Render(int ghWheresTarget);

	// 終了処理
	void Finalize();

	// ターゲットがアクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// このターゲットを出現させる関数
	void Spawn(Vector2D position);

	// 境界ボックスを取得する関数
	RECT GetBoundingBox() const;

	// 座標を取得する関数
	Vector2D GetPosition() const { return m_position; }

	// 衝突したら呼び出される関数
	void OnHit() { m_isActive = false; }

};
