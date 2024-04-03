#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//画像読込
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define TITLE_PATH	"Data/Play/title.png"
#define ENTER_PATH	"Data/Play/enter.png"

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() {
	// タイトル画像の読込
	BackHan   = LoadGraph(BACK_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	titleHan = LoadGraph(TITLE_PATH);
	enterHan  = LoadGraph(ENTER_PATH);

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

	//エンターキーでプレイ画面へ遷移
	if (CheckHitKey(KEY_INPUT_RETURN))
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
	DrawGraph(0, 0, titleHan, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, entertouka);
	DrawGraph(0, 0, enterHan, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//タイトル終了処理
void SceneTitle::FinTitle() {
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
