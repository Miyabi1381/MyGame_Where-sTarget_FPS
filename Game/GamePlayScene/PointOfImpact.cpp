#include "PointOfImpact.h"


// �R���X�g���N�^
PointOfImpact::PointOfImpact()
	: m_position{}
	, m_animationState{ AnimationState::AnimNone }
	, m_animationCounter{ 0 }
{
}




// �X�V����
void PointOfImpact::Update()
{
	// �A�j���[�V�����X�e�[�g�̐ݒ肪�Ȃ��ꍇ�X�V���Ȃ�
	if (m_animationState == AnimationState::AnimNone) return;

	// �J�E���^�[�����Z���ĕ\���Ԋu�𐔂���
	m_animationCounter++;

	// �J�E���^�[��
	if (m_animationCounter > ANIMATION_INTERVAL)
	{

	}
}



// �`�揈��
void PointOfImpact::Render(int ghWheresTarget)
{

}



// �w�肵���ʒu�ɒ��e�G�t�F�N�g��\������֐�
void PointOfImpact::OnHit(POINT position)
{

}
