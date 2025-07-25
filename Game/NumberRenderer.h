#pragma once

// ������\������N���X
class NumberRenderer
{
	// �萔�錾 -------------------------------------------------
public:

	// �����̊G�̑傫��
	static constexpr int NUMBER_WIDTH = 16;
	static constexpr int NUMBER_HEIGHT = 24;

	// �����o�ϐ��̐錾 -----------------------------------------
private:

	// �\���ʒu
	POINT m_position;

	// �\������
	int m_digit;

	// �����O�l�߂���ꍇ��true��ݒ肷��
	bool m_isZeroPadding;

	// �ݒ肳��Ă��錅���ŕ\���ł��鐔���̍ő�l
	int m_max;

	// �\�����鐔��
	int m_number;

	// �\�����鐔���̑傫��
	int m_width;
	int m_height;

	// �����o�֐��̐錾 -----------------------------------------
public:

	// �R���X�g���N�^
	NumberRenderer(POINT position, int digit, bool isZeroPadding = false);

	// �`�揈��
	void Render(int ghWheresTarget);

	// �\�����鐔����ݒ肷��֐�
	void SetNumber(int number) { m_number = number; }

	// �����̑傫����ݒ肷��֐�
	void SetSize(int width, int height)
	{
		m_width = width;
		m_height = height;
	}
};
