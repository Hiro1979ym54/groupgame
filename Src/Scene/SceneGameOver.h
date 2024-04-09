#pragma once

class SceneGameOver {
private:
	//画像用変数
	int GameoverHan = 0;
	int GroundHan	= 0;
	int PlayerHan	= 0;

	//BGM
	int GameoverBGMHan = 0;

	//プレイヤー座標
	float PlayerX = 620.0f;
	float PlayerY = 300.0f;

	//プレイヤー上下処理用
	int Player_sw = 0;

	//地面のスライド処理用変数
	int GroundPosX	= 0;
	int GroundPosX2	= 1280;
	
public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();		// ゲームオーバー初期化

	void StepGameOver();		// ゲームオーバー通常処理

	void DrawGameOver();		// ゲームオーバー描画処理

	void FinGameOver();		    // ゲームオーバー終了処理
};