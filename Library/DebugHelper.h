/**
 * @file   GameLibDebug.h
 *
 * @brief  デバッグ関連のヘッダファイル
 *
 * @author S.Takaki
 *
 * @date   2025/03/13
 */

// 多重インクルードの防止 =====================================================
#pragma once




// ヘッダファイルの読み込み ===================================================
#include <cwchar>        // swprintf()
#include <stdexcept>     // runtime_error()
#include <string>        // wstring
#include <vector>        // vector

#include <debugapi.h>    // OutputDebugString()




// 関数の定義 =================================================================
/**
 * @brief 出力ウインドウに文字列を出力
 *
 * @param[in] format   書式
 * @param[in] firstArg 書式用第１引数
 * @param[in] args     書式用可変引数
 *
 * @return なし
 */
template <typename T, typename ... Args>
void OutputDebugString(const wchar_t* format, const T& firstArg, const Args& ... args)
{
	// フォーマット済みの文字列の長さを取得
	int textLength = std::swprintf(nullptr, 0, format, firstArg, args ...);
	if (textLength < 0)
	{
		throw std::runtime_error("String Formatting Error.");
	}


	// フォーマット済みの文字列の生成
	std::vector<wchar_t> buffer(textLength + 1);    // 終端文字'\0'の分として+1
	std::swprintf(buffer.data(), buffer.size(), format, firstArg, args ...);


	// 出力ウインドウに文字列を出力
	OutputDebugString(buffer.data());
}
