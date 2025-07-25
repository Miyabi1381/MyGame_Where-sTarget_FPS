/**
* @file AIM.h
* 
* @brief 照準に関するヘッダーファイル
* 
* @autor Frira
* 
* @date 2025/07/08
*/


// 多重インクルードの防止 ===========================================
#pragma once



// ヘッダファイルの読み込み
#include "Game/GameMath.h"



// クラスの定義
class AIM
{
	// クラス定数の宣言 ---------------------------------------------
public:

	// 発射したかどうか
	bool m_shot;

	// 大きさ
	static constexpr float SIZE = 32.0f;


	// データメンバの宣言 -------------------------------------------
private:

	// 位置
	Vector2D m_position;
	
	// メンバ関数の宣言 ---------------------------------------------
public:

	// コンストラクタ
	AIM();

	// デストラクタ
	~AIM();

	// 初期化処理
	void Initialize(Vector2D position);

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

	// 描画関数
	void Render(int ghWheresTarget);

	// 終了処理
	void Finalize();

	// プレイヤーの中心の位置を取得する関数
	Vector2D GetCenterPosition();
};