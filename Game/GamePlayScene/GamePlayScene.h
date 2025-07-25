/**
* @file		GamePlayScene.h
* 
* @brief	ゲームシーンに関するヘッダーファイル
* 
* @autor	Frira
* 
* @date		2025/07/02
*/


// 多重インクルードの防止 =====================================================
#pragma once



// ヘッダファイルの読み込み ===================================================
#include "Game/Screen.h"
#include "Game/GameMath.h"

#include "Target.h"
#include "AIM.h"


// クラスの前方宣言
class Game;

class GamePlayScene
{
	// 列挙型の宣言 -------------------------------------------------
private:

	// ゲームの状態
	enum class GameState
	{
		NONE = -1,		// エラー
		GAMEPLAY,		// ゲームプレイ中
		GAMEOVER,		// ゲームオーバー
		GAMECLEAR,		// ゲームクリア
	};


	// クラス定数の宣言 -------------------------------------------------
public:

	// フォントサイズ
	static constexpr int FONT_SIZE = 50;

	// ゲームオーバーの文字列
	static constexpr wchar_t GAMEOVER[] = L"Game Over";

	// ゲームクリアの文字列
	static constexpr wchar_t GAMECLEAR[] = L"Game Clear";


	// データメンバの宣言 -----------------------------------------------
private:

	// 絵のグラフィックハンドル
	int m_ghWheresTarget;

	// 照準
	AIM m_AIM;

	// ターゲット
	Target m_target;

	// このシーンを含むゲームオブジェクトへのポインタ
	Game* m_pGame;

	// ゲームの状態
	GameState m_gameState;


	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	GamePlayScene(Game* pGame);

	// デストラクタ
	~GamePlayScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();


private:

	// ゲームクリアか調べる関数
	bool IsGameClear();

	// ゲームオーバーか調べる関数
	bool IsGameOver();

};