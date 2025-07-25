/**
 * @file   GameLibTime.h
 *
 * @brief  時間関連のヘッダファイル
 *
 * @author S.Takaki
 *
 * @date   2025/03/10
 */

// 多重インクルードの防止 =====================================================
#pragma once




// クラスの定義 ===============================================================
namespace GameLib
{
	/**
	 * @brief フレームタイマー
	 */
	class FrameTimer final
	{
		// クラス定数の宣言 --------------------------------------------
		private:
			static constexpr LONGLONG ONE_SECOND            = 1'000'000;    ///< 1秒 (=1,000,000μ秒)
			static constexpr int      MAX_DELTA_TIME_FACTOR = 5;            ///< 外れ値の許容倍率



		// データメンバの宣言 --------------------------------------------
		private:
			// 設定用
			bool     m_isFixedFPS;           ///< フレームレートを固定するかどうか(true:固定, false:可変)
			LONGLONG m_targetElapsedTime;    ///< 目標経過時間[ns]

			// 計測用
			LONGLONG m_lastTime;    ///< 前回の計測時間[ns]
			
			// 固定FPS用
			LONGLONG m_accumulatedTime;    ///< 前フレームからの累積時間[ns]

			// フレームレート用
			LONGLONG m_startTime;      ///< フレームレート計測開始時間[ns]
			LONGLONG m_elapsedTime;    ///< フレームの経過時間[ns]
			int      m_frameCount;     ///< フレーム数[f]
			int      m_frameRate;      ///< フレームレート[f/s]

			// 更新フラグ用
			bool m_isUpdateFrame;    ///< 更新を行うべきフレームかどうか(true:更新を行うフレーム, false:更新を行わないフレーム)



		// メンバ関数の宣言 -----------------------------------------------
		/// @name コンストラクタ／デストラクタ
		/// @{
		public:
			/**
			 * @brief 可変FPS用のコンストラクタ
			 *
			 * @param なし
			 */
			FrameTimer();


			/**
			 * @brief 固定FPS用のコンストラクタ
			 *
			 * @param[in] fps フレームレート
			 */
			FrameTimer(int fps);


			/**
			 * @brief デストラクタ
			 */
			~FrameTimer() = default;
		/// @}


		/// @name 操作
		/// @{
		public:
			/**
			 * @brief 計測データのリセット
			 *
			 * @param なし
			 *
			 * @return なし
			 */
			void Reset();


			/**
			 * @brief フレームタイマーの更新処理
			 *
			 * @param なし
			 *
			 * @return なし
			 */
			void Update();


			/**
			 * @brief ゲームの更新を行うべきフレームかどうか
			 *
			 * @param なし
			 *
			 * @retval true  ゲームの更新を行うフレーム
			 * @retval false ゲームの更新を行わないフレーム
			 */
			bool IsUpdateFrame() const;
		/// @}


		/// @name 設定／取得
		/// @{
		public:
			/**
			 * @brief 直前のフレームからの経過時間の取得
			 *
			 * @param なし
			 *
			 * @return 直前のフレームからの経過時間[s]
			 */
			float GetElapsedTime() const;

			
			/**
			 * @brief フレームレートの取得
			 * 
			 * @param なし
			 * 
			 * @return 現在のフレームレート[fps]
			 */
			int GetFrameRate() const;
		/// @}
	};

} // namespace GameLib