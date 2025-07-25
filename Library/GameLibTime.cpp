/**
 * @file   GameLibTime.cpp
 *
 * @brief  ���Ԋ֘A�̃\�[�X�t�@�C��
 *
 * @author S.Takaki
 *
 * @date   2025/03/12
 */

// �w�b�_�t�@�C���̓ǂݍ��� ===================================================
#include "GameLibTime.h"

#include <DxLib.h>




// �����o�֐��̒�` ===========================================================
namespace GameLib
{
    //*********************************************************************
    // 
    // �t���[���^�C�}�[
    // 
    //*********************************************************************
    //-----------------------------------------------------------------
    // �R���X�g���N�^
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
    // �v���f�[�^�̃��Z�b�g
    //-----------------------------------------------------------------
    void FrameTimer::Reset()
    {
        // �v���p
        m_lastTime = GetNowHiPerformanceCount();

        // �Œ�FPS�p
        m_accumulatedTime = 0;

        // �t���[�����[�g�p
        m_startTime   = m_lastTime;
        m_elapsedTime = ONE_SECOND;
        m_frameCount  = 0;
        m_frameRate   = 0;

        // �X�V�t���O�p
        m_isUpdateFrame = false;
    }



	//-----------------------------------------------------------------
	// �X�V
	//-----------------------------------------------------------------
    void FrameTimer::Update()
    {
        // ���ݎ��Ԃ̌v��
        LONGLONG currentTime = GetNowHiPerformanceCount();

        // �t���[���̌o�ߎ��Ԃ̎Z�o
        LONGLONG deltaTime = currentTime - m_lastTime;


        // �O��l�ւ̑Ή�
        if (deltaTime > m_targetElapsedTime * MAX_DELTA_TIME_FACTOR)
        {
            deltaTime = m_targetElapsedTime;
        }


        // �t���[���̌o�ߎ��Ԃ̍X�V
        if (m_isFixedFPS)
        {
            // �Œ�FPS�̏ꍇ
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
            // ��FPS�̏ꍇ
            m_isUpdateFrame = true;
            m_frameCount++;
            m_elapsedTime = deltaTime;
        }


        // 1�b���Ƀt���[�����[�g�̍X�V
        if ((currentTime - m_startTime) >= ONE_SECOND)
        {
            m_frameRate  = m_frameCount;
        	m_frameCount = 0;
            m_startTime  = currentTime;
        }


        // ���݂̌v�����Ԃ̕ۑ�
        m_lastTime = currentTime;
    }



    //-----------------------------------------------------------------
    // �Q�[���̍X�V���s���ׂ��t���[�����ǂ���
    //-----------------------------------------------------------------
    bool FrameTimer::IsUpdateFrame() const
    {
        return m_isUpdateFrame;
    }



    //-----------------------------------------------------------------
    // ���O�̃t���[������̌o�ߎ��Ԃ̎擾
    //-----------------------------------------------------------------
    float FrameTimer::GetElapsedTime() const
    {
        return static_cast<float>(m_elapsedTime) / ONE_SECOND;
    }



    //-----------------------------------------------------------------
    // �t���[�����[�g�̎擾
    //-----------------------------------------------------------------
    int FrameTimer::GetFrameRate() const
    {
        return m_frameRate;
    }
} // namespace GameLib
