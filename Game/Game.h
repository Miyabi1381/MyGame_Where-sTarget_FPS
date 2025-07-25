/**
 * @file   Game.h
 *
 * @brief  ゲーム全体に関するヘッダファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// 多重インクルードの防止 =====================================================
#pragma once




// ヘッダファイルの読み込み ===================================================
#include "Screen.h"



// 各シーンのヘッダー
#include "TitleScene/TitleScene.h"
#include "GamePlayScene/GamePlayScene.h"
#include "GameOverScene/GameOverScene.h"




// クラスの宣言 ===============================================================




// クラスの定義 ===============================================================
/**
 * @brief ゲーム
 */
class Game
{
// 列挙型の定義 -----------------------------------------------------
public:
	enum class SceneID
	{
		NONE = -1,
		TITLE,
		GAMEPLAY,
		GAMEOVER,
	};

// クラス定数の宣言 -------------------------------------------------
public:
	// システム関連
	static constexpr const wchar_t* TITLE = L"Where's Target?";   ///< ゲームタイトル


// データメンバの宣言 -----------------------------------------------
private:
	// 入力関連
	int m_key;       ///< 現在のキー情報
	int m_oldKey;    ///< 前回のキー情報

	// シーン関連
	SceneID m_currentSceneID;	///< 現在のシーンID
	SceneID m_requestedSceneID;	///< 変更要求のシーンID

	// 各シーンの変数
	TitleScene m_titleScene;		///< タイトルシーン
	GamePlayScene m_gamePlayScene;	///< ゲームプレイシーン
	GameOverScene m_gameOverScene;	///< ゲームプレイシーン


// メンバ関数の宣言 -------------------------------------------------
// コンストラクタ/デストラクタ
public:
	// コンストラクタ
	Game();

	// デストラクタ
	~Game();


// 操作
public:
	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(float elapsedTime);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

	// シーンを変更をリクエストする関数
	void RequestSceneChange(SceneID nextSceneID);


// 内部実装
private:

	// 開始シーンの設定関数
	void SetStartScene(SceneID sceneID);

	// シーンを変更する関数
	void ChangeScene();

	// 現在のシーンの初期化処理
	void InitializeCurrentScene();

	// 現在のシーンの更新処理
	void UpdateCurrentScene(int KeyCondition, int KeyTrigger);

	// 現在のシーンの描画処理
	void RenderCurrentScene();

	// 現在のシーンの終了処理
	void FinalizeCurrentScene();


};
