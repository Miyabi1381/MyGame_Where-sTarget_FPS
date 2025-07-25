#include "Target.h"
#include "Game/Screen.h"
#include <cstdlib>
#include <ctime>




// コンストラクタ
Target::Target()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
	, m_angle{ 0.0f }
{
}



// デストラクタ
Target::~Target()
{
}



// 初期化関数
void Target::Initialize(Vector2D position)
{
	// 出現位置を設定する
	m_position = position;

	// ランダムに初期角度を設定
	m_angle = static_cast<float>(rand()) / RAND_MAX * 2.0f * 3.1415926f;

	// 初速ベクトル
	m_velocity.x = std::cosf(m_angle) * Target::SPEED;
	m_velocity.y = std::sinf(m_angle) * Target::SPEED;
}



// 更新関数
void Target::Update()
{
	// 緩やかに方向を変える
	float deltaAngle = ((rand() / (float)RAND_MAX) - 0.5f) * 0.6f;	// -0.3 ～ 0.3f Rad
	m_angle += deltaAngle;

	// 速度を角度から再計算する
	m_velocity.x = std::cosf(m_angle) * Target::SPEED;
	m_velocity.y = std::sinf(m_angle) * Target::SPEED;

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

		// X軸が画面外なら
	if ((m_position.x < 0) ||
		(m_position.x + Target::SIZE > Screen::WIDTH))
	{
		m_angle = 3.1415926f - m_angle;	// 角度を反転させる
	}

	// Y軸が画面外なら
	if ((m_position.y < 0) ||
		(m_position.y + Target::SIZE > Screen::HEIGHT))
	{
		m_angle = -m_angle;	// 角度を反転させる
	}
	
}



// 描画関数
void Target::Render(int ghShootingGame)
{
	// ターゲットの描画
	DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y), 
						static_cast<int>(m_position.x) + Target::SIZE, static_cast<int>(m_position.y) + Target::SIZE,
						64, 0, 64, 64,
						ghShootingGame, TRUE);
}



// 終了処理
void Target::Finalize()
{
}

// このターゲットを出現させる関数
void Target::Spawn(Vector2D position)
{
	// アクティブにする
	m_isActive = true;

	// ターゲットを初期化する
	Initialize(position);
}



// 境界ボックスを取得する関数
RECT Target::GetBoundingBox() const
{
	RECT rect{};

	rect.left = static_cast<int>(m_position.x);
	rect.right = static_cast<int>(m_position.x) + Target::SIZE;
	rect.top = static_cast<int>(m_position.y);
	rect.bottom = static_cast<int>(m_position.y) + Target::SIZE;

	return rect;
}
