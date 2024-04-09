#pragma once

class SceneClear {
private:
	//画像用変数
	int GameclearHan = 0;
	int GroundHan = 0;
	int PlayerHan = 0;

	//BGM
	int GameclearBGMHan = 0;

	//プレイヤー座標
	float PlayerX = 620.0f;
	float PlayerY = 300.0f;

	//プレイヤー上下処理用
	int Player_sw = 0;

	//地面のスライド処理用変数
	int GroundPosX = 0;
	int GroundPosX2 = 1280;
public:
	SceneClear();
	~SceneClear();

	void InitClear();		// クリア初期化

	void StepClear();		// クリア通常処理

	void DrawClear();		// クリア描画処理

	void FinClear();		//クリア終了処理

};
