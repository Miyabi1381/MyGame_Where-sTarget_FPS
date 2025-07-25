/**
 * @file   WinMain.cpp
 * 
 * @brief  ゲームプログラムのエントリーポイント
 * 
 * @author S.Takaki
 * 
 * @date   2025/03/13
 */

// ヘッダファイルの読み込み ===================================================
#include "EmbeddedResources/Resource.h"
#include "Game/Game.h"
#include "Game/Screen.h"




// 関数宣言 ===================================================================
void DrawFrameRate(int x, int y, unsigned int color, int fps);




// 関数定義 ===================================================================
/**
 * @brief プログラムのエントリーポイント
 * 
 * @param[in] hInstance     現在のインスタンスのハンドル
 * @param[in] hPrevInstance 以前のインスタンスのハンドル(常にNULL)
 * @param[in] lpCmdLine     コマンドライン
 * @param[in] nCmdShow      ウィンドウの表示状態
 * 
 * @retval  0 正常終了
 * @retval -1 異常終了
 */
int APIENTRY wWinMain(_In_     HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_     LPWSTR    lpCmdLine,
                      _In_     int       nCmdShow)
{
    // 未使用引数の警告対策
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(nCmdShow);


#if defined(_DEBUG)
    // メモリーリーク検出機構のセットアップ
    SetUpMemoryLeakDetector();
#endif


    // デバッグ情報用ログファイルの出力の抑制
    SetOutApplicationLogValidFlag(FALSE);


    // 起動モードの設定
#if defined(_DEBUG)
    ChangeWindowMode(TRUE);	           // ウインドウモードで実行
    SetMainWindowText(Game::TITLE);    // ウインドウタイトルの設定
    SetWindowIconID(IDI_ICON1);        // ウインドウアイコンの設定
#else
    ChangeWindowMode(FALSE);	      // フルスクリーンで実行
#endif


    // 初期状態の画面モードの設定
    SetGraphMode(Screen::WIDTH, Screen::HEIGHT, 32);


    // DXライブラリの初期化処理
    if (DxLib_Init() == -1)
    {
        return -1;    // エラーが起きたら直ちに終了
    }


    // 描画先を裏画面に設定
    SetDrawScreen(DX_SCREEN_BACK);


    // フレームタイマーの生成
    GameLib::FrameTimer frameTimer{ 60 };    // 60FPSを指定


    // ゲームオブジェクトの生成
    Game game;


    // ゲームの処理
    game.Initialize();    // ゲームの初期化処理

    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        frameTimer.Update();      // フレームタイマーの更新

        if (frameTimer.IsUpdateFrame())
        {
            game.Update(frameTimer.GetElapsedTime());    // ゲームの更新処理
        }
        game.Render();    // ゲームの描画処理


#if defined(_DEBUG)
        DrawFrameRate(10, 10, Colors::WHITE, frameTimer.GetFrameRate());    // FPSの描画
#endif

        ScreenFlip();               // 裏画面の内容を表画面に反映
        ClearDrawScreen();          // 裏画面の消去
    }

    game.Finalize();      // ゲームの終了処理


    // DXライブラリの終了処理
    if (DxLib_End() == -1)
    {
        return -1;    // エラーが起きたら直ちに終了
    }


    return 0;    // 正常終了
}



/**
 * @brief フレームレートの描画
 *
 * @param[in] x     X座標
 * @param[in] y     Y座標
 * @param[in] color 描画色
 * @param[in] fps   描画色
 *
 * @return なし
 */
void DrawFrameRate(int x, int y, unsigned int color, int fps)
{
    // フォントの生成
    static const int fontHandle = CreateFontToHandle(nullptr, 16, 10);


    // FPSの描画
    DrawFormatStringToHandle(x, y, color, fontHandle, L"%3dfps", fps);
}