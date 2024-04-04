#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"

//画像
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define READY_PATH	"Data/Play/ready.png"

#define PLAYER_PATH	"Data/Play/playeranime1.png"

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

	if (PlayerX <= 440) {
		DrawGraph(0, 0, ReadyHan, true);
	}
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
}
