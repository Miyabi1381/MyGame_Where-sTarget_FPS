#include "pch.h"
#include "NumberRenderer.h"

// �R���X�g���N�^
NumberRenderer::NumberRenderer(
	POINT position,
	int digit,
	bool isZeroPadding
)
	: m_position{ position }
	, m_digit{ digit }
	, m_isZeroPadding{ isZeroPadding }
	, m_max{ 0 }
	, m_number{ 0 }
	, m_width{ NUMBER_WIDTH }
	, m_height{ NUMBER_HEIGHT }
{
	// �\���̍ő�l�����߂�i�R���Ȃ�X�X�X�j
	m_max = 1;
	for (int i = 0; i < m_digit; i++)
	{
		m_max *= 10;
	}
	m_max--;
}

// �`�揈��
void NumberRenderer::Render(int ghSpriteSheet)
{
	// �������P�����[�N�փR�s�[����
	int number = m_number;

	// �����𒴂��鐔���̏ꍇ�͂��̌��ŕ\���ł���ő�l�ɂ���
	if (number > m_max)
	{
		number = m_max;
	}

	// ������`�悷��
	for (int i = 0; i < m_digit; i++)
	{
		// �e����X���W�̕\���ʒu�̃I�t�Z�b�g�l
		int offsetX = (m_digit - i - 1) * m_width;

		// �����̕`��
		DrawRectExtendGraph(
			m_position.x + offsetX, m_position.y,
			m_position.x + offsetX + m_width, m_position.y + m_height,
			0 + (number % 10) * NUMBER_WIDTH, 48, NUMBER_WIDTH, NUMBER_HEIGHT,
			ghSpriteSheet, TRUE);

		// ���̌���
		number /= 10;

		// ���̂O�l�߂����Ȃ��̂Ń��[�v�𔲂���
		if ((number == 0) && (m_isZeroPadding == false)) break;
	}
}
