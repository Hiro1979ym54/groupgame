#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneGameOver.h"
#include "../Input/Input.h"

//画像
#define GAMEOVER_PATH	"Data/Play/gameover.png"
#define GROUND_PATH		"Data/Play/ground.png"
#define PLAYER_PATH		"Data/Play/gameoverplayer.png"

//BGM
#define GAMEOVER_BACKGROUND		"Data/Sound/GameOverBGM.mp3"

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// ゲームオーバー初期化
void SceneGameOver::InitGameOver() {
	// ゲームオーバー画像の読込
	GameoverHan = LoadGraph(GAMEOVER_PATH);
	GroundHan	= LoadGraph(GROUND_PATH);
	PlayerHan	= LoadGraph(PLAYER_PATH);

	//BGM読込
	GameoverBGMHan = LoadSoundMem(GAMEOVER_BACKGROUND);

	//BGM再生
	PlaySoundMem(GameoverBGMHan, DX_PLAYTYPE_LOOP, true);

	g_CurrentSceneId = SCENE_ID_LOOP_GAMEOVER;
}

// ゲームオーバー通常処理
void SceneGameOver::StepGameOver() {
	//地面のスクロール処理
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_GAMEOVER;
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

}

// ゲームオーバー描画処理
void SceneGameOver::DrawGameOver() {
	//画像描画
	DrawGraph(0, 0, GameoverHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX, PlayerY, PlayerHan, true);
}

//ゲームオーバー終了処理
void SceneGameOver::FinGameOver() {
	//BGM後処理
	DeleteSoundMem(GameoverBGMHan);

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
