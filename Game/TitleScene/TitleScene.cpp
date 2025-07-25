//--------------------------------------------------------------------------------------
// File: TitleScene.cpp
//
//--------------------------------------------------------------------------------------
#include "TitleScene.h"
#include "Game/Game.h"


// コンストラクタ
TitleScene::TitleScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// デストラクタ
TitleScene::~TitleScene()
{

}

// 初期化処理
void TitleScene::Initialize()
{

}

// 更新処理
void TitleScene::Update(int keyCondition, int keyTrigger)
{
	// スペースキーが押されたら
	if (keyTrigger & PAD_INPUT_10)
	{
		// ゲームプレイシーンへ
		m_pGame->RequestSceneChange(Game::SceneID::GAMEPLAY);
	}
}

// 描画処理
void TitleScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"Titleシーン");
}

// 終了処理
void TitleScene::Finalize()
{

}

