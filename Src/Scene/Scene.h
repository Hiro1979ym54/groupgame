#pragma once

enum SCENE_ID
{
	//タイトルシーンID
	SCENE_ID_INIT_TITLE,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//プレイシーンID
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//クリアシーンID
	SCENE_ID_INIT_CLEAR,
	SCENE_ID_LOOP_CLEAR,
	SCENE_ID_FIN_CLEAR,

	//ゲームオーバーシーンID
	SCENE_ID_INIT_GAMEOVER,
	SCENE_ID_LOOP_GAMEOVER,
	SCENE_ID_FIN_GAMEOVER,
};

//　現在のシーンID
extern SCENE_ID g_CurrentSceneId;