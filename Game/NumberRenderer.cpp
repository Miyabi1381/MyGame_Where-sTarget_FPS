#include "pch.h"
#include "NumberRenderer.h"

// コンストラクタ
NumberRenderer::NumberRenderer(
	POINT position,
	int digit,
	bool isZeroPadding
)
	: m_position{ position }
	, m_digit{ digit }
	, m_isZeroPadding{ isZeroPadding }
	, m_max{ 0 }
	, m_number{ 0 }
	, m_width{ NUMBER_WIDTH }
	, m_height{ NUMBER_HEIGHT }
{
	// 表示の最大値を求める（３桁なら９９９）
	m_max = 1;
	for (int i = 0; i < m_digit; i++)
	{
		m_max *= 10;
	}
	m_max--;
}

// 描画処理
void NumberRenderer::Render(int ghSpriteSheet)
{
	// 数字を１次ワークへコピーする
	int number = m_number;

	// 桁数を超える数字の場合はその桁で表示できる最大値にする
	if (number > m_max)
	{
		number = m_max;
	}

	// 数字を描画する
	for (int i = 0; i < m_digit; i++)
	{
		// 各桁のX座標の表示位置のオフセット値
		int offsetX = (m_digit - i - 1) * m_width;

		// 数字の描画
		DrawRectExtendGraph(
			m_position.x + offsetX, m_position.y,
			m_position.x + offsetX + m_width, m_position.y + m_height,
			0 + (number % 10) * NUMBER_WIDTH, 48, NUMBER_WIDTH, NUMBER_HEIGHT,
			ghSpriteSheet, TRUE);

		// 次の桁へ
		number /= 10;

		// 桁の０詰めをしないのでループを抜ける
		if ((number == 0) && (m_isZeroPadding == false)) break;
	}
}
