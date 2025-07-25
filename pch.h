// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。

#ifndef PCH_H
#define PCH_H

// プリコンパイルするヘッダーをここに追加します

// Windows ヘッダー ファイル
#define WIN32_LEAN_AND_MEAN    // Windows ヘッダーからほとんど使用されていない部分を除外する
#define NOMINMAX               // min, maxマクロを定義しない
#include <windows.h>


// C++標準ライブラリ
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>


// DXライブラリ関連
#include <DxLib.h>


// 自作ライブラリ
#include "Library/DebugHelper.h"
#include "Library/GameLib.h"
#include "Library/MemoryLeakDetector.h"



#endif //PCH_H
