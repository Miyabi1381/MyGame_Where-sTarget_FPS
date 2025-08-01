#include "PointOfImpact.h"


// �R���X�g���N�^
PointOfImpact::PointOfImpact()
	: m_position{}
	, m_animationState{ AnimationState::AnimNone }
	, m_animationCounter{ 0 }
	, m_isActive{ false }
{
}




// �X�V����
void PointOfImpact::Update()
{
	// �A�j���[�V�����X�e�[�g�̐ݒ肪�Ȃ��ꍇ�X�V���Ȃ�
	if (m_animationState == AnimationState::AnimNone) return;

	// �J�E���^�[�����Z���ĕ\���Ԋu�𐔂���
	m_animationCounter++;

	// �J�E���^�[���A�j���Ԋu���������Ȃ�����X�V
	if (m_animationCounter > ANIMATION_INTERVAL)
	{
		// �A�j���[�V�����J�E���^�[�����Z�b�g
		m_animationCounter = 0;

		// �Ō�̊G�Ȃ�A�j���[�V�������I������
		if (m_animationState == AnimationState::Anim04)
		{
			// ���g�p��Ԃɖ߂�
			m_animationState = AnimationState::AnimNone;
		}
		else
		{
			// ���̊G�ɐ؂�ւ���
			m_animationState = static_cast<AnimationState>(static_cast<int>(m_animationState) + 1);	// int�^��1�����āA������A�j���[�V�����ɂł���悤�ɕϊ�
		}
	}
}



// �`�揈��
void PointOfImpact::Render(int ghWheresTarget)
{
	// �A�j���[�V�����X�e�[�g�̐ݒ肪�Ȃ��ꍇ�`�悵�Ȃ�
	if (m_animationState == AnimationState::AnimNone) return;

	// �X�v���C�g�V�[�g��̊G�̈ʒu���擾
	int x = POINT_OF_IMPACT[static_cast<int>(m_animationState)].x;
	int y = POINT_OF_IMPACT[static_cast<int>(m_animationState)].y;

	// ���e�G�t�F�N�g�̕`��
	DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y),
						static_cast<int>(m_position.x) + PointOfImpact::SIZE, static_cast<int>(m_position.y) + PointOfImpact::SIZE,
						x, y, 16, 16,
						ghWheresTarget, TRUE);
}



// �w�肵���ʒu�ɒ��e�G�t�F�N�g��\������֐�
void PointOfImpact::PointHit(Vector2D position)
{
	// ���ɃA�j���[�V�������Ȃ���s���Ȃ�
	if (m_animationState != AnimationState::AnimNone) return;

	// ���e�̕\���ʒu���w��
	m_position = Vector2D{ position.x - PointOfImpact::SIZE / 2,position.y - PointOfImpact::SIZE / 2 };

	// �A�j���[�V�����J�E���^�[��������
	m_animationCounter = 0;

	// �A�j���[�V�����X�e�[�g���ŏ��̊G�ɐݒ�
	m_animationState = AnimationState::Anim01;

	// �A�N�e�B�u�ɂ���
	m_isActive = true;
}



// ���E�{�b�N�X���擾����֐�
RECT PointOfImpact::GetBoundingBox() const
{
	return RECT{
	static_cast<LONG>(m_position.x),
	static_cast<LONG>(m_position.y),
	static_cast<LONG>(m_position.x + SIZE),
	static_cast<LONG>(m_position.y + SIZE)
	};
}