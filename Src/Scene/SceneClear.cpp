#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneClear.h"
#include "../Input/Input.h"

SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// ゲームクリア初期化
void SceneClear::InitClear() {
	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// ゲームクリア通常処理
void SceneClear::StepClear() {
	g_CurrentSceneId = SCENE_ID_FIN_CLEAR;

}

// ゲームクリア描画処理
void SceneClear::DrawClear() {

}

//ゲームクリア終了処理
void SceneClear::FinClear() {
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
