/**
 * @file   GameLibTime.h
 *
 * @brief  ���Ԋ֘A�̃w�b�_�t�@�C��
 *
 * @author S.Takaki
 *
 * @date   2025/03/10
 */

// ���d�C���N���[�h�̖h�~ =====================================================
#pragma once




// �N���X�̒�` ===============================================================
namespace GameLib
{
	/**
	 * @brief �t���[���^�C�}�[
	 */
	class FrameTimer final
	{
		// �N���X�萔�̐錾 --------------------------------------------
		private:
			static constexpr LONGLONG ONE_SECOND            = 1'000'000;    ///< 1�b (=1,000,000�ʕb)
			static constexpr int      MAX_DELTA_TIME_FACTOR = 5;            ///< �O��l�̋��e�{��



		// �f�[�^�����o�̐錾 --------------------------------------------
		private:
			// �ݒ�p
			bool     m_isFixedFPS;           ///< �t���[�����[�g���Œ肷�邩�ǂ���(true:�Œ�, false:��)
			LONGLONG m_targetElapsedTime;    ///< �ڕW�o�ߎ���[ns]

			// �v���p
			LONGLONG m_lastTime;    ///< �O��̌v������[ns]
			
			// �Œ�FPS�p
			LONGLONG m_accumulatedTime;    ///< �O�t���[������̗ݐώ���[ns]

			// �t���[�����[�g�p
			LONGLONG m_startTime;      ///< �t���[�����[�g�v���J�n����[ns]
			LONGLONG m_elapsedTime;    ///< �t���[���̌o�ߎ���[ns]
			int      m_frameCount;     ///< �t���[����[f]
			int      m_frameRate;      ///< �t���[�����[�g[f/s]

			// �X�V�t���O�p
			bool m_isUpdateFrame;    ///< �X�V���s���ׂ��t���[�����ǂ���(true:�X�V���s���t���[��, false:�X�V���s��Ȃ��t���[��)



		// �����o�֐��̐錾 -----------------------------------------------
		/// @name �R���X�g���N�^�^�f�X�g���N�^
		/// @{
		public:
			/**
			 * @brief ��FPS�p�̃R���X�g���N�^
			 *
			 * @param �Ȃ�
			 */
			FrameTimer();


			/**
			 * @brief �Œ�FPS�p�̃R���X�g���N�^
			 *
			 * @param[in] fps �t���[�����[�g
			 */
			FrameTimer(int fps);


			/**
			 * @brief �f�X�g���N�^
			 */
			~FrameTimer() = default;
		/// @}


		/// @name ����
		/// @{
		public:
			/**
			 * @brief �v���f�[�^�̃��Z�b�g
			 *
			 * @param �Ȃ�
			 *
			 * @return �Ȃ�
			 */
			void Reset();


			/**
			 * @brief �t���[���^�C�}�[�̍X�V����
			 *
			 * @param �Ȃ�
			 *
			 * @return �Ȃ�
			 */
			void Update();


			/**
			 * @brief �Q�[���̍X�V���s���ׂ��t���[�����ǂ���
			 *
			 * @param �Ȃ�
			 *
			 * @retval true  �Q�[���̍X�V���s���t���[��
			 * @retval false �Q�[���̍X�V���s��Ȃ��t���[��
			 */
			bool IsUpdateFrame() const;
		/// @}


		/// @name �ݒ�^�擾
		/// @{
		public:
			/**
			 * @brief ���O�̃t���[������̌o�ߎ��Ԃ̎擾
			 *
			 * @param �Ȃ�
			 *
			 * @return ���O�̃t���[������̌o�ߎ���[s]
			 */
			float GetElapsedTime() const;

			
			/**
			 * @brief �t���[�����[�g�̎擾
			 * 
			 * @param �Ȃ�
			 * 
			 * @return ���݂̃t���[�����[�g[fps]
			 */
			int GetFrameRate() const;
		/// @}
	};

} // namespace GameLib