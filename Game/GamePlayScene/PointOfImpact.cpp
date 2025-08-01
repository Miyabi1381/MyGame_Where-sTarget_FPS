#include "PointOfImpact.h"


// コンストラクタ
PointOfImpact::PointOfImpact()
	: m_position{}
	, m_animationState{ AnimationState::AnimNone }
	, m_animationCounter{ 0 }
	, m_isActive{ false }
{
}




// 更新処理
void PointOfImpact::Update()
{
	// アニメーションステートの設定がない場合更新しない
	if (m_animationState == AnimationState::AnimNone) return;

	// カウンターを加算して表示間隔を数える
	m_animationCounter++;

	// カウンターがアニメ間隔よりも多くなったら更新
	if (m_animationCounter > ANIMATION_INTERVAL)
	{
		// アニメーションカウンターをリセット
		m_animationCounter = 0;

		// 最後の絵ならアニメーションを終了する
		if (m_animationState == AnimationState::Anim04)
		{
			// 未使用状態に戻す
			m_animationState = AnimationState::AnimNone;
		}
		else
		{
			// 次の絵に切り替える
			m_animationState = static_cast<AnimationState>(static_cast<int>(m_animationState) + 1);	// int型で1足して、それをアニメーションにできるように変換
		}
	}
}



// 描画処理
void PointOfImpact::Render(int ghWheresTarget)
{
	// アニメーションステートの設定がない場合描画しない
	if (m_animationState == AnimationState::AnimNone) return;

	// スプライトシート上の絵の位置を取得
	int x = POINT_OF_IMPACT[static_cast<int>(m_animationState)].x;
	int y = POINT_OF_IMPACT[static_cast<int>(m_animationState)].y;

	// 着弾エフェクトの描画
	DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y),
						static_cast<int>(m_position.x) + PointOfImpact::SIZE, static_cast<int>(m_position.y) + PointOfImpact::SIZE,
						x, y, 16, 16,
						ghWheresTarget, TRUE);
}



// 指定した位置に着弾エフェクトを表示する関数
void PointOfImpact::PointHit(Vector2D position)
{
	// 既にアニメーション中なら実行しない
	if (m_animationState != AnimationState::AnimNone) return;

	// 着弾の表示位置を指定
	m_position = Vector2D{ position.x - PointOfImpact::SIZE / 2,position.y - PointOfImpact::SIZE / 2 };

	// アニメーションカウンターを初期化
	m_animationCounter = 0;

	// アニメーションステートを最初の絵に設定
	m_animationState = AnimationState::Anim01;

	// アクティブにする
	m_isActive = true;
}



// 境界ボックスを取得する関数
RECT PointOfImpact::GetBoundingBox() const
{
	return RECT{
	static_cast<LONG>(m_position.x),
	static_cast<LONG>(m_position.y),
	static_cast<LONG>(m_position.x + SIZE),
	static_cast<LONG>(m_position.y + SIZE)
	};
}