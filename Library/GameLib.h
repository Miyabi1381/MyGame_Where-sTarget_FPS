/**
 * @file   GameLib.h
 *
 * @brief  ゲーム制作用ライブラリのヘッダファイル
 *
 * @author S.Takaki
 *
 * @date   2025/03/12
 */

// 多重インクルードの防止 =====================================================
#pragma once




 // ヘッダファイルの読み込み ==================================================
#include "GameLibTime.h"




// 定数の定義 =================================================================
namespace Colors
{
	/// @name 標準カラー(16色)
	/// @{
	static constexpr unsigned int BLACK   = 0xFF000000;    ///< 黒
	static constexpr unsigned int BLUE    = 0xFF0000FF;    ///< 青
	static constexpr unsigned int CYAN    = 0xFF00FFFF;    ///< シアン
	static constexpr unsigned int GRAY    = 0xFF808080;    ///< 灰色
	static constexpr unsigned int GREEN   = 0xFF008000;    ///< 緑色
	static constexpr unsigned int LIME    = 0xFF00FF00;    ///< ライム
	static constexpr unsigned int MAGENTA = 0xFFFF00FF;    ///< マゼンタ
	static constexpr unsigned int MAROON  = 0xFF800000;    ///< マルーン
	static constexpr unsigned int NAVY    = 0xFF000080;    ///< ネイビー
	static constexpr unsigned int OLIVE   = 0xFF808000;    ///< オリーブ
	static constexpr unsigned int PURPLE  = 0xFF800080;    ///< 紫
	static constexpr unsigned int RED     = 0xFFFF0000;    ///< 赤
	static constexpr unsigned int SILVER  = 0xFFC0C0C0;    ///< 銀色
	static constexpr unsigned int TEAL    = 0xFF008080;    ///< ティール
	static constexpr unsigned int WHITE   = 0xFFFFFFFF;    ///< 白
	static constexpr unsigned int YELLOW  = 0xFFFFFF00;    ///< 黄色
	/// @}

} // namespace Colors




// 関数の定義 =================================================================
namespace GameLib
{
	/**
	 * @brief ゲームの終了
	 *
	 * @param なし
	 *
	 * @return なし
	 */
	inline void ExitGame()
	{
		PostQuitMessage(0);
	}
} // namespace GameLib
