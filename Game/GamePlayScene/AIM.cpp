/**
* @file AIM.cpp
*
* @brief 照準に関するソースファイル
*
* @autor Frira
*
* @date 2025/07/08
*/
#include "AIM.h"
#include "Game/Screen.h"


// コンストラクタ
AIM::AIM()
	: m_position{ 0 }
	, m_pointOfImpact{}
{
}


// デストラクタ
AIM::~AIM()
{
}


// 初期化処理
void AIM::Initialize(Vector2D position)
{
	// 位置の初期化
	m_position = position;
}


// 更新処理
void AIM::Update(int keyCondition, int keyTrigger)
{
	// マウスの座標を取得する
	int mouseX{}, mouseY{};
	GetMousePoint(&mouseX, &mouseY);

	// マウスの位置に画像を表示する
	m_position.x = static_cast<float>(mouseX) - AIM::SIZE / 2;
	m_position.y = static_cast<float>(mouseY) - AIM::SIZE / 2;

	// 左クリックされたら
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{

		// 弾を発射する(着弾)
		Vector2D hitPosition =
		{
			m_position.x + AIM::SIZE / 2,
			m_position.y + AIM::SIZE / 2
		};

		// 着弾エフェクトの表示
		m_pointOfImpact.PointHit(hitPosition);
	}

	// 着弾エフェクトの更新
	m_pointOfImpact.Update();
}


// 描画処理
void AIM::Render(int ghWheresTarget)
{
	// カーソルの描画
	DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y), 
						static_cast<int>(m_position.x + AIM::SIZE), static_cast<int>(m_position.y + AIM::SIZE),
					    0, 0, 64, 64,
					    ghWheresTarget, TRUE);

	// 着弾エフェクトの描画
	m_pointOfImpact.Render(ghWheresTarget);

	// デバッグ当たり判定(ちゃくだん)
	RECT impactBox = m_pointOfImpact.GetBoundingBox();
	DrawBox(impactBox.left, impactBox.top, impactBox.right, impactBox.bottom, GetColor(0, 0, 255), FALSE);

}


// 終了処理
void AIM::Finalize()
{
}


// プレイヤーの中心の位置を取得する関数
Vector2D AIM::GetCenterPosition()
{
	return Vector2D
	{
		m_position.x + AIM::SIZE / 2,
		m_position.y + AIM::SIZE / 2
	};
}



// PointOfImpact への参照を取得する
PointOfImpact& AIM::GetPointOfImpact()
{
	return m_pointOfImpact;
}
