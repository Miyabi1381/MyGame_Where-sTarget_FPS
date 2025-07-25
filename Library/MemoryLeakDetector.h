/**
 * @file   MemoryLeakDetector.h
 *
 * @brief  メモリーリーク検出関連のヘッダファイル
 *
 * @author S.Takaki
 *
 * @date   2023/04/05
 */

// 多重インクルード防止 =======================================================
#pragma once




// ヘッダファイルの読み込み ===================================================
#if defined(_DEBUG)
  #include <crtdbg.h>
#endif




// マクロ定義 =================================================================
#if defined(_DEBUG)
  #define _CRTDBG_MAP_ALLOC
  #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif




// 関数定義 ===================================================================

/**
 * @brief メモリーリーク検出機構のセットアップ
 * 
 * @param なし
 * 
 * @return なし
 */
inline void SetUpMemoryLeakDetector()
{
#if defined(_DEBUG)
	// メモリーリーク検出のための設定
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
#endif
}
