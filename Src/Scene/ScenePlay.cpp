#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"
#include "../map/map.h"
#include "../Collison/Collison.h"

#define	SCREEN_SIZE_X	1280	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720		// Y方向の画面サイズを指定

//画像
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define READY_PATH	"Data/Play/ready.png"
#define PLAYER_PATH	"Data/Play/playeranime1.png"

<<<<<<< Updated upstream
//画像の横のサイズ、縦のサイズ
#define PLAYER_WIDTH (50)	//横サイズ
#define PLAYER_WIDTH (50)	//縦サイズ

=======
//BGM
#define PLAY_BACKGROUND		"Data/Sound/PlayBGM.mp3"
>>>>>>> Stashed changes

//回転量用円周率
#define PI    3.1415926535897932384626433832795f


#define GRAVITY (0.5f)	// 重力加速度
#define SIZE	(50)	// キャラクターのサイズ

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

<<<<<<< Updated upstream
//Mapの構造体宣言
MapChip map;

=======
>>>>>>> Stashed changes
// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込
	BackHan		= LoadGraph(BACK_PATH);
	GroundHan	= LoadGraph(GROUND_PATH);
	PlayerHan	= LoadGraph(PLAYER_PATH);
	ReadyHan	= LoadGraph(READY_PATH);
	src_handle	= LoadGraph(MAP_CHIP_IMG_PATH_UP);
	src_handle2 = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);
	src_handle3 = LoadGraph(MAP_CHIP_IMG_PATH_UP);
	src_handle4 = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);
<<<<<<< Updated upstream
	

	//プレイヤーの横と縦のサイズ
	plsize_W = PLAYER_WIDTH;
	plsize_H = PLAYER_WIDTH;

	//プレイヤーの生存フラグ
	PlyerisAlive = true;

	//プレイヤーの当たり判定のフラグ
	bool isHit = true;

	//マップの横と縦のサイズ
	map.Mapsize_W = DOKAN_WIDTH;
	map.Mapsize_H = DOKAN_HEIGHT;
=======

	//各変数初期化
	PlayerX		= 620.0f;
	PlayerY		= 300.0f;
	SpacePush	= false;
	isJump		= false;
		
	//BGM読込
	PlayBGMHan = LoadSoundMem(PLAY_BACKGROUND);

	//BGM再生
	PlaySoundMem(PlayBGMHan, DX_PLAYTYPE_LOOP, true);
>>>>>>> Stashed changes

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	PlayerX += 10;

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
	//一度でもジャンプしたら上下移動を終了
	if (!SpacePush) {
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

	//ジャンプ用のキーが押されたらジャンプ

	if (IsKeyPush(KEY_INPUT_SPACE)) {
		isUp = true;
		Yspeed = -jump_power;
		//一度でも押されていたらスペースフラグをtrueに
		SpacePush = true;
	}

	//土管の当たり判定
	if (isHit == true) {
		//IsHitRectの定義
		if (IsHitRect(PlayerX, PlayerY, plsize_W, plsize_H
			, map.x, map.y,
			map.Mapsize_W, map.Mapsize_H == -1)) {
			PlyerisAlive = false;
		}
	}

	//重力を与える
	if (SpacePush) {
		isUp = false;
		Yspeed += GRAVITY;
		PlayerY += Yspeed;
	}

	//床判定
	if (PlayerY >= 547) {
		isJump = false;
		isClear = false;
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX - ScreenX, PlayerY, PlayerHan, true);

	//マップの縦の数だけ繰り返す
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++) {

		//マップの横の数だけ繰り返す
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++) {

<<<<<<< Updated upstream
			DrawGraph(mapChip[x_index][y_index].x,mapChip[x_index][y_index].y, src_handle, true);
			DrawGraph(mapChip[x_index][y_index].x,mapChip[x_index][y_index].y, src_handle2, true);
=======
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle , true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle2, true);
>>>>>>> Stashed changes
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle3, true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle4, true);
		}
	}

<<<<<<< Updated upstream

	//後でプレイヤーの回転量を変更
	/*if (!isUp) {
		DrawRotaGraph(PlayerX, PlayerY, 1.0, PI / 0.52, PlayerHan, true);
	}

	if (isUp) {
		DrawRotaGraph(PlayerX, PlayerY, 1.0, PI / 0.1, PlayerHan, true);
	}*/

=======
>>>>>>> Stashed changes
	//ready画像はジャンプ開始したら表示しない
	if (SpacePush == false) {
		DrawGraph(0, 0, ReadyHan, true);
	}
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	//BGM後処理
	DeleteSoundMem(PlayBGMHan);

	//クリアフラグを確認して遷移先を決定
	if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}
}

void ScenePlay::InitScreen()
{
	ScreenX = PlayerX - SCREEN_SIZE_X / 2;
}

//スクリーンのワールド座標
void ScenePlay::StepScreen()
{
	ScreenX = PlayerX + 200 - SCREEN_SIZE_X / 2;
}
