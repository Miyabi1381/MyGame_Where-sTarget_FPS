//--------------------------------------------------------------------------------------
// File: GameOverScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GameOverScene.h"
#include "Game/Game.h"


// コンストラクタ
GameOverScene::GameOverScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// デストラクタ
GameOverScene::~GameOverScene()
{

}

// 初期化処理
void GameOverScene::Initialize()
{

}

// 更新処理
void GameOverScene::Update(int keyCondition, int keyTrigger)
{
	// ゲームクリアした場合
	if (true)
	{

	}

	// スペースキーが押されたら
	if (keyTrigger & PAD_INPUT_10)
	{
		// ゲームプレイシーンへ
		m_pGame->RequestSceneChange(Game::SceneID::GAMEPLAY);
	}
}

// 描画処理
void GameOverScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GameOverシーン");
}

// 終了処理
void GameOverScene::Finalize()
{

}

