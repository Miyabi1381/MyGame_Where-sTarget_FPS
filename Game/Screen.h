/**
 * @file   Screen.h
 *
 * @brief  ゲーム画面に関するヘッダファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// 多重インクルードの防止 =====================================================
#pragma once




// クラスの定義 ===============================================================
/**
  * @brief 画面
  */
class Screen
{
// クラス定数の宣言
public:
	static constexpr int WIDTH    = 1280;          // 画面の幅[pixel]
	static constexpr int HEIGHT   =  720;          // 画面の高さ[pixel]

	static constexpr int TOP      = 0;             // 画面の上端[pixel]
	static constexpr int BOTTOM   = HEIGHT;        // 画面の下端[pixel]
	static constexpr int LEFT     = 0;             // 画面の左端[pixel]
	static constexpr int RIGHT    = WIDTH;         // 画面の右端[pixel]

	static constexpr int CENTER_X = WIDTH  / 2;    // 画面の中央(X座標)[pixel]
	static constexpr int CENTER_Y = HEIGHT / 2;    // 画面の中央(Y座標)[pixel]
};
