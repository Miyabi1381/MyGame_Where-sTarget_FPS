#pragma once

// 数字を表示するクラス
class NumberRenderer
{
	// 定数宣言 -------------------------------------------------
public:

	// 数字の絵の大きさ
	static constexpr int NUMBER_WIDTH = 16;
	static constexpr int NUMBER_HEIGHT = 24;

	// メンバ変数の宣言 -----------------------------------------
private:

	// 表示位置
	POINT m_position;

	// 表示桁数
	int m_digit;

	// 桁を０詰めする場合はtrueを設定する
	bool m_isZeroPadding;

	// 設定されている桁数で表示できる数字の最大値
	int m_max;

	// 表示する数字
	int m_number;

	// 表示する数字の大きさ
	int m_width;
	int m_height;

	// メンバ関数の宣言 -----------------------------------------
public:

	// コンストラクタ
	NumberRenderer(POINT position, int digit, bool isZeroPadding = false);

	// 描画処理
	void Render(int ghWheresTarget);

	// 表示する数字を設定する関数
	void SetNumber(int number) { m_number = number; }

	// 数字の大きさを設定する関数
	void SetSize(int width, int height)
	{
		m_width = width;
		m_height = height;
	}
};
