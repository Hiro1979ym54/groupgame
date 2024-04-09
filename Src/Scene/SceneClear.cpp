#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneClear.h"
#include "../Input/Input.h"

//画像
#define GAMECLEAR_PATH	"Data/Play/gameclear.png"
#define GROUND_PATH		"Data/Play/ground.png"
#define PLAYER_PATH		"Data/Play/clearplayer.png"

//BGM
#define GAMECLEAR_BACKGROUND		"Data/Sound/ClearBGM.mp3"

SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// ゲームクリア初期化
void SceneClear::InitClear() {
	// ゲームオーバー画像の読込
	GameclearHan = LoadGraph(GAMECLEAR_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	PlayerHan = LoadGraph(PLAYER_PATH);

	//BGM読込
	GameclearBGMHan = LoadSoundMem(GAMECLEAR_BACKGROUND);

	//BGM再生
	PlaySoundMem(GameclearBGMHan, DX_PLAYTYPE_LOOP, true);

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// ゲームクリア通常処理
void SceneClear::StepClear() {
	//地面のスクロール処理
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
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
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_CLEAR;
	}

}

// ゲームクリア描画処理
void SceneClear::DrawClear() {
	//画像描画
	DrawGraph(0, 0, GameclearHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX, PlayerY, PlayerHan, true);
}

//ゲームクリア終了処理
void SceneClear::FinClear() {
	//BGM後処理
	DeleteSoundMem(GameclearBGMHan);

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
