#include "GamePlayScene.h"


// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_ghWheresTarget{ -1 }
	, m_AIM{}
	, m_target{}
	, m_pGame{ pGame }
	, m_gameState{}
{
}


// デストラクタ
GamePlayScene::~GamePlayScene()
{
}


// 初期化処理
void GamePlayScene::Initialize()
{
	// 絵の読み込み
	m_ghWheresTarget = LoadGraph(L"Resources/Textures/Where's_Target.png");

	// 照準の初期化
	Vector2D startPosition = Vector2D{ Screen::CENTER_X, Screen::CENTER_Y };
	m_AIM.Initialize(startPosition);

	// ターゲットの初期化
	Vector2D position = Vector2D{ static_cast<float>(GetRand(Screen::WIDTH - Target::SIZE)), static_cast<float>(GetRand(Screen::HEIGHT - Target::SIZE)) };
	m_target.Initialize(position);

}


// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// ターゲットの更新
	m_target.Update();

	// 照準の更新
	m_AIM.Update(keyCondition, keyTrigger);
	
}


// 描画処理
void GamePlayScene::Render()
{
	// ターゲットの描画
	m_target.Render(m_ghWheresTarget);

	// 照準の描画
	m_AIM.Render(m_ghWheresTarget);

}


// 終了処理
void GamePlayScene::Finalize()
{
	// ターゲットの終了
	m_target.Finalize();

	// 照準の終了
	m_AIM.Finalize();

}


// ゲームクリアか調べる関数
bool GamePlayScene::IsGameClear()
{
	return false;
}


// ゲームオーバーか調べる関数
bool GamePlayScene::IsGameOver()
{
	return false;
}
