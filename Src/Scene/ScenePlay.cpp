#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"

#define	SCREEN_SIZE_X	1280	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720		// Y方向の画面サイズを指定

//画像
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define READY_PATH	"Data/Play/ready.png"

#define PLAYER_PATH	"Data/Play/playeranime1.png"

#define PI    3.1415926535897932384626433832795f


#define GRAVITY (0.5f)	// 重力加速度
#define SIZE	(50)	// キャラクターのサイズ

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込
	BackHan = LoadGraph(BACK_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	PlayerHan = LoadGraph(PLAYER_PATH);
	ReadyHan = LoadGraph(READY_PATH);

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	//地面のスクロール処理
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	//プレイ画面に遷移したらプレイヤーを左へ移動
	if (PlayerX >= 440) {
		PlayerX -= 4;
	}

	//プレイヤーの上下処理
	//一度でもジャンプしたら上下移動を終了
	if (!SpacePush) {
		switch (Player_sw) {
		case 0:
			PlayerY += 0.5f;
			if (PlayerY >= 305) {
				Player_sw = 1;
			}
			break;
		case 1:
			PlayerY -= 0.5f;
			if (PlayerY <= 295) {
				Player_sw = 0;
			}
			break;
		}
	}

	//ジャンプ用のキーが押されたらジャンプ
	if (IsKeyPush(KEY_INPUT_SPACE)){
		isUp = true;
		Yspeed = -jump_power;
		//一度でも押されていたらスペースフラグをtrueに
		SpacePush = true;
	}

	//重力を与える
	if (SpacePush) {
		isUp = false;
		Yspeed += GRAVITY;
		PlayerY += Yspeed;
	}

	//床判定
	if (PlayerY >= 547) {
		PlayerY = 547;
		isJump = false;
	}

	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX, PlayerY, PlayerHan, true);

	//後でプレイヤーの回転量を変更
	/*if (!isUp) {
		DrawRotaGraph(PlayerX, PlayerY, 1.0, PI / 0.52, PlayerHan, true);
	}

	if (isUp) {
		DrawRotaGraph(PlayerX, PlayerY, 1.0, PI / 0.1, PlayerHan, true);
	}*/

	//ready画像はジャンプ開始したら表示しない
	if (PlayerX <= 440 && SpacePush == false) {
		DrawGraph(0, 0, ReadyHan, true);
	}
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
}
