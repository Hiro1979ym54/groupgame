#pragma once

class ScenePlay {
private:
	//画像用変数
	int BackHan = 0;
	int GroundHan = 0;
	int ReadyHan = 0;

	int PlayerHan = 0;

	float PlayerX = 620;
	float PlayerY = 300;

	int Player_sw = 0;

	//地面のスライド処理用変数
	int GroundPosX = 0;
	int GroundPosX2 = 1280;
public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		// クリア初期化

	void StepPlay();		// クリア通常処理

	void DrawPlay();		// クリア描画処理

	void FinPlay();			//プレイ終了処理
};
