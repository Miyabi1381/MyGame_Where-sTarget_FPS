#include "PointOfImpact.h"


// コンストラクタ
PointOfImpact::PointOfImpact()
	: m_position{}
	, m_animationState{ AnimationState::AnimNone }
	, m_animationCounter{ 0 }
{
}




// 更新処理
void PointOfImpact::Update()
{
	// アニメーションステートの設定がない場合更新しない
	if (m_animationState == AnimationState::AnimNone) return;

	// カウンターを加算して表示間隔を数える
	m_animationCounter++;

	// カウンターが
	if (m_animationCounter > ANIMATION_INTERVAL)
	{

	}
}



// 描画処理
void PointOfImpact::Render(int ghWheresTarget)
{

}



// 指定した位置に着弾エフェクトを表示する関数
void PointOfImpact::OnHit(POINT position)
{

}
