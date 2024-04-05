#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneGameOver.h"
#include "../Input/Input.h"

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// ゲームオーバー初期化
void SceneGameOver::InitGameOver() {
	g_CurrentSceneId = SCENE_ID_LOOP_GAMEOVER;
}

// ゲームオーバー通常処理
void SceneGameOver::StepGameOver() {
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_GAMEOVER;
	}

}

// ゲームオーバー描画処理
void SceneGameOver::DrawGameOver() {

}

//ゲームオーバー終了処理
void SceneGameOver::FinGameOver() {
	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
