#include "GamePlayScene.h"
#include "Game/Game.h"


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
	
	// 衝突判定
	CheckEnemyColliedWithPlayerBullet();

	// ゲームクリア判定
	if (IsGameClear())
	{
		// ゲームオーバーシーンへ
		m_pGame->RequestSceneChange(Game::SceneID::GAMEOVER);
	}
	else if (IsGameOver())
	{
		// ゲームオーバーシーンへ
		m_pGame->RequestSceneChange(Game::SceneID::GAMEOVER);
	}
}


// 描画処理
void GamePlayScene::Render()
{
	// ターゲットの描画
	m_target.Render(m_ghWheresTarget);

	// デバッグ当たり判定(たーげっと)
	RECT targetBox = m_target.GetBoundingBox();
	DrawBox(targetBox.left, targetBox.top, targetBox.right, targetBox.bottom, GetColor(255, 0, 0), FALSE);

	// 照準の描画
	m_AIM.Render(m_ghWheresTarget);
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"ゲームプレイシーン");

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
	// ターゲットが死んだらクリア
	if (!m_target.IsActive()) return true;

	return false;
}


// ゲームオーバーか調べる関数
bool GamePlayScene::IsGameOver()
{
	return false;
}



// ターゲットと弾(着弾エフェクト)との衝突判定
void GamePlayScene::CheckEnemyColliedWithPlayerBullet()
{
	// 着弾エフェクトの参照
	PointOfImpact& pointOfImpact = m_AIM.GetPointOfImpact();

	// 着弾エフェクトのが非アクティブなら判定しない
	if (!pointOfImpact.IsActive()) return;

	// ターゲットが非アクティブなら判定しない
	if (!m_target.IsActive()) return;

	// それぞれの矩形を取得
	RECT pointRect = pointOfImpact.GetBoundingBox();
	RECT targetRect = m_target.GetBoundingBox();

	// 衝突判定
	RECT result;
	if (IntersectRect(&result, &pointRect, &targetRect))
	{
		// 当たっていたらターゲットを消す
		m_target.OnHit();
	}
}