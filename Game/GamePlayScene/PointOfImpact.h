#pragma once


class PointOfImpact
{
private:

	// ���e�̃A�j���[�V�����X�e�[�g
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, 
		Anim02, 
		Anim03, 
		Anim04,
	};


	// �萔�錾
private:

	// ���e�A�j���[�V�����̊��o
	static constexpr int ANIMATION_INTERVAL = 4;

	// ���e�G�t�F�N�g�̃T�C�Y
	static constexpr int SIZE = 32;

	// �����̃X�v���C�g�V�[�g��̃O���t�B�b�N�̈ʒu
	static constexpr POINT POINT_OF_IMPACT[] =
	{
		{ 0 + 16 * 0, 152 },		// �p�^�[���P
		{ 0 + 16 * 1, 152 },		// �p�^�[���Q
		{ 0 + 16 * 2, 152 },		// �p�^�[���R
		{ 0 + 16 * 3, 152 },		// �p�^�[���S
	};


	// �f�[�^�����o�̐錾
private:

	// �\���ʒu
	POINT m_position;

	// �A�j���[�V�����X�e�[�g
	AnimationState m_animationState;

	// ���e�A�j���[�V�����J�E���^�[
	int m_animationCounter;


public:

	// �R���X�g���N�^
	PointOfImpact();

	// �X�V����
	void Update();

	// �`�揈��
	void Render(int ghWheresTarget);

	// �w�肵���ʒu�ɒ��e�G�t�F�N�g��\������֐�
	void OnHit(POINT position);

};