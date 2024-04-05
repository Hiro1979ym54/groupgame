#pragma once

class ScenePlay {
private:
	//画像用変数
	int BackHan = 0;
	int GroundHan = 0;
	int ReadyHan = 0;
	int PlayerHan = 0;

	//プレイヤー座標
	float PlayerX = 620.0f;
	float PlayerY = 300.0f;
	float PlayercurrentY = 0.0f;

	//プレイヤー上下処理用
	int Player_sw = 0;

	//プレイヤーの回転量変更用変数
	int PlayerRota = 0;

	//スペースが押されたか確認するフラグ
	bool SpacePush = false;

	//ジャンプ中か確認するフラグ
	bool isJump = false;

	float Yspeed = 0.0f;

	//プレイヤーが上昇中か調べるフラグ
	bool isUp = false;

	//ジャンプ量
	float jump_power = 7.0f;

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
