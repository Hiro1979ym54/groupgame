#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//画像読込
#define TITLE_BACK_PATH		"Data/Play/back.png"
#define TITLE_GROUND_PATH	"Data/Play/ground.png"

//地面のスライド処理用変数
int GroundPosX = 0;
int GroundPosX2 = 1280;

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() {
	// タイトル画像の読込
	BackHan = LoadGraph(TITLE_BACK_PATH);
	GroundHan = LoadGraph(TITLE_GROUND_PATH);

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle() {
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	//エンターキーでプレイ画面へ遷移
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void SceneTitle::DrawTitle() {
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 0, GroundHan, true);
	DrawGraph(GroundPosX2, 0, GroundHan, true);
}

//タイトル終了処理
void SceneTitle::FinTitle() {
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
