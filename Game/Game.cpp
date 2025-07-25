/**
 * @file   Game.cpp
 *
 * @brief  ゲーム全体に関するソースファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// ヘッダファイルの読み込み ===================================================
#include "Game.h"

#include "Game/Screen.h"




// メンバ関数の定義 ===========================================================
/**
 * @brief デフォルトコンストラクタ
 *
 * @param なし
 */
Game::Game()
	: m_key{ 0 }
	, m_oldKey{ 0 }
	, m_currentSceneID{ SceneID::NONE }
	, m_requestedSceneID{ SceneID::NONE }
	, m_titleScene{ this }
	, m_gamePlayScene{ this }
	, m_gameOverScene{ this }
{
	// 乱数の初期値を設定
	SRand(static_cast<int>(time(nullptr)));
}



/**
 * @brief デストラクタ
 */
Game::~Game()
{

}



/**
 * @brief 初期化処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Initialize()
{
	// ゲームの初期化

	// 起動時のシーンをタイトルに設定する
	SetStartScene(SceneID::TITLE);
}



/**
 * @brief 更新処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Update(float elapsedTime)
{
	// ゲームの更新

	// キー入力の取得
	m_oldKey = m_key;
	m_key    = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// キートリガー
	int keyTrigger = ~m_oldKey & m_key;

	if (m_requestedSceneID != SceneID::NONE)
	{
		ChangeScene();
	}

	// 現在実行中のシーンの更新
	UpdateCurrentScene(m_key, keyTrigger);
}



/**
 * @brief 描画処理
 *
 * @param[in] なし
 *
 * @return なし
 */
void Game::Render()
{
	// ゲームの描画

	// 現在実行中のシーンの描画
	RenderCurrentScene();

}



/**
 * @brief 終了処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Finalize()
{
	// ゲームの終了処理

	// 現在実行中のシーンの描画
	FinalizeCurrentScene();
}



/**
 * @brief シーンを変更をリクエストする関数
 *
 * @param なし
 *
 * @return なし
 */
void Game::RequestSceneChange(SceneID nextSceneID)
{
	m_requestedSceneID = nextSceneID;
}



/**
 * @brief 開始シーンの設定関数
 *
 * @param なし
 *
 * @return なし
 */
void Game::SetStartScene(SceneID sceneID)
{
	// 現在のシーンを呼び出す
	m_currentSceneID = sceneID;

	// シーンの初期化
	InitializeCurrentScene();
}



/**
 * @brief シーンを変更する関数
 *
 * @param なし
 *
 * @return なし
 */
void Game::ChangeScene()
{
	// 現在進行中のシーンを終了させる
	FinalizeCurrentScene();

	// シーンを変更する
	m_currentSceneID = m_requestedSceneID;

	// シーンを初期化する
	InitializeCurrentScene();

	// シーンの変更リクエストを初期化する
	m_requestedSceneID = SceneID::NONE;	
}



/**
 * @brief 現在のシーンの初期化処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::InitializeCurrentScene()
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Initialize();
		break;

	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Initialize();
		break;

	case Game::SceneID::GAMEOVER:
		m_gameOverScene.Initialize();
		break;

	default:
		break;
	}
}



/**
 * @brief 現在のシーンの更新処理
 *
 * @param[in] KeyCondition
 * @param[in] KeyTrigger
 *
 * @return なし
 */
void Game::UpdateCurrentScene(int KeyCondition, int KeyTrigger)
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Update(KeyCondition, KeyTrigger);
		break;

	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Update(KeyCondition, KeyTrigger);
		break;

	case Game::SceneID::GAMEOVER:
		m_gameOverScene.Update(KeyCondition, KeyTrigger);
		break;

	default:
		break;
	}
}



/**
 * @brief 現在のシーンの描画処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::RenderCurrentScene()
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Render();
		break;

	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Render();
		break;

	case Game::SceneID::GAMEOVER:
		m_gameOverScene.Render();
		break;

	default:
		break;
	}
}



/**
 * @brief 現在のシーンの終了処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::FinalizeCurrentScene()
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Finalize();
		break;

	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Finalize();
		break;

	case Game::SceneID::GAMEOVER:
		m_gameOverScene.Finalize();
		break;

	default:
		break;
	}
}
