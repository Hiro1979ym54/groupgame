#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	g_CurrentSceneId = SCENE_ID_FIN_PLAY;

}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {

}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
}
