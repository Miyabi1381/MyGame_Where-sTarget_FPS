/**
 * @file   GameLibTime.cpp
 *
 * @brief  時間関連のソースファイル
 *
 * @author S.Takaki
 *
 * @date   2025/03/12
 */

// ヘッダファイルの読み込み ===================================================
#include "GameLibTime.h"

#include <DxLib.h>




// メンバ関数の定義 ===========================================================
namespace GameLib
{
    //*********************************************************************
    // 
    // フレームタイマー
    // 
    //*********************************************************************
    //-----------------------------------------------------------------
    // コンストラクタ
    //-----------------------------------------------------------------
    FrameTimer::FrameTimer()
        : m_isFixedFPS{ false }
        , m_targetElapsedTime{ ONE_SECOND / GetRefreshRate() }
    {
        Reset();
    }



    FrameTimer::FrameTimer(int fps)
        : m_isFixedFPS{ true }
        , m_targetElapsedTime{ ONE_SECOND / std::min(fps, GetRefreshRate()) }
    {
        Reset();
    }



    //-----------------------------------------------------------------
    // 計測データのリセット
    //-----------------------------------------------------------------
    void FrameTimer::Reset()
    {
        // 計測用
        m_lastTime = GetNowHiPerformanceCount();

        // 固定FPS用
        m_accumulatedTime = 0;

        // フレームレート用
        m_startTime   = m_lastTime;
        m_elapsedTime = ONE_SECOND;
        m_frameCount  = 0;
        m_frameRate   = 0;

        // 更新フラグ用
        m_isUpdateFrame = false;
    }



	//-----------------------------------------------------------------
	// 更新
	//-----------------------------------------------------------------
    void FrameTimer::Update()
    {
        // 現在時間の計測
        LONGLONG currentTime = GetNowHiPerformanceCount();

        // フレームの経過時間の算出
        LONGLONG deltaTime = currentTime - m_lastTime;


        // 外れ値への対応
        if (deltaTime > m_targetElapsedTime * MAX_DELTA_TIME_FACTOR)
        {
            deltaTime = m_targetElapsedTime;
        }


        // フレームの経過時間の更新
        if (m_isFixedFPS)
        {
            // 固定FPSの場合
            m_accumulatedTime += deltaTime;

            m_isUpdateFrame = (m_accumulatedTime >= m_targetElapsedTime);
            if (m_isUpdateFrame)
            {
                m_frameCount++;
                m_elapsedTime = m_targetElapsedTime;
                m_accumulatedTime -= m_targetElapsedTime;
            }
        }
        else
        {
            // 可変FPSの場合
            m_isUpdateFrame = true;
            m_frameCount++;
            m_elapsedTime = deltaTime;
        }


        // 1秒毎にフレームレートの更新
        if ((currentTime - m_startTime) >= ONE_SECOND)
        {
            m_frameRate  = m_frameCount;
        	m_frameCount = 0;
            m_startTime  = currentTime;
        }


        // 現在の計測時間の保存
        m_lastTime = currentTime;
    }



    //-----------------------------------------------------------------
    // ゲームの更新を行うべきフレームかどうか
    //-----------------------------------------------------------------
    bool FrameTimer::IsUpdateFrame() const
    {
        return m_isUpdateFrame;
    }



    //-----------------------------------------------------------------
    // 直前のフレームからの経過時間の取得
    //-----------------------------------------------------------------
    float FrameTimer::GetElapsedTime() const
    {
        return static_cast<float>(m_elapsedTime) / ONE_SECOND;
    }



    //-----------------------------------------------------------------
    // フレームレートの取得
    //-----------------------------------------------------------------
    int FrameTimer::GetFrameRate() const
    {
        return m_frameRate;
    }
} // namespace GameLib
