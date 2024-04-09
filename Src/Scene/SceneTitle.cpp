#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//画像読込
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define TITLE_PATH	"Data/Play/title.png"
#define ENTER_PATH	"Data/Play/enter.png"

#define PLAYER_PATH	"Data/Play/player.png"

//BGM
#define TITLE_BACKGROUND		"Data/Sound/TitleBGM.mp3"

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() {
	// タイトル画像の読込
	BackHan   = LoadGraph(BACK_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	titleHan  = LoadGraph(TITLE_PATH);
	enterHan  = LoadGraph(ENTER_PATH);

	PlayerHan = LoadGraph(PLAYER_PATH);

	//BGM読込
	TitleBGMHan = LoadSoundMem(TITLE_BACKGROUND);

	//BGM再生
	PlaySoundMem(TitleBGMHan, DX_PLAYTYPE_LOOP, true);

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle() {
	//地面のスクロール処理
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	//エンターのチカチカ処理
	switch (entertouka_sw) {
	case 0:
		entertouka += 9;
		if (entertouka >= 255) {
			entertouka_sw = 1;
		}
		break;
	case 1:
		entertouka -= 9;
		if (entertouka <= 0) {
			entertouka_sw = 0;
		}
		break;
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

	//エンターキーでプレイ画面へ遷移
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void SceneTitle::DrawTitle() {
	//画像描画
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(0, -50, titleHan, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, entertouka);
	DrawGraph(0, 0, enterHan, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawGraph(PlayerX, PlayerY, PlayerHan, true);
}

//タイトル終了処理
void SceneTitle::FinTitle() {
	//BGM後処理
	DeleteSoundMem(TitleBGMHan);

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
