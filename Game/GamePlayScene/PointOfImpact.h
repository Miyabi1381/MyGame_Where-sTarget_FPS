#pragma once

#include "Game/GameMath.h"


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
public:

	// ���e�A�j���[�V�����̊Ԋu
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
	Vector2D m_position;

	// �A�j���[�V�����X�e�[�g
	AnimationState m_animationState;

	// ���e�A�j���[�V�����J�E���^�[
	int m_animationCounter;

	// �A�N�e�B�u�t���O
	bool m_isActive;


public:

	// �R���X�g���N�^
	PointOfImpact();

	// �X�V����
	void Update();

	// �`�揈��
	void Render(int ghWheresTarget);

	// �w�肵���ʒu�ɒ��e�G�t�F�N�g��\������֐�
	void PointHit(Vector2D position);

	// ���W���擾����֐�
	Vector2D GetPosition() const { return m_position; }

	// ���E�{�b�N�X���擾����֐�
	RECT GetBoundingBox() const;

	// ���˂����e�������ǂ����̔���
	bool IsActive() const { return m_isActive; }
};