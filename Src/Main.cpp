//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include "Scene/Scene.h"
#include "Scene/SceneTitle.h"
#include "Scene/ScenePlay.h"
#include "Scene/SceneClear.h"
#include "Scene/SceneGameOver.h"
#include "Input/Input.h"
#include "map/map.h"

// define
#define	SCREEN_SIZE_X	1280	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720		// Y方向の画面サイズを指定

// 現在のシーンID
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//入力制御初期化
	InitInput();

	SceneTitle  Title;			// クラス宣言
	ScenePlay   Play;
	SceneClear clear;
	SceneGameOver gameover;
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();

		StepInput();				//入力制御ステップ

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------
		
		switch (g_CurrentSceneId)
		{
		case SCENE_ID_INIT_TITLE:
		{
			// タイトルの初期化
			Title.InitTitle();
		}
		break;
		case SCENE_ID_LOOP_TITLE:
		{
			// タイトルの通常処理
			Title.StepTitle();

			// タイトルの描画処理
			Title.DrawTitle();
		}
		break;
		case SCENE_ID_FIN_TITLE:
		{
			// タイトルの初期化
			Title.FinTitle();
		}
		break;
		case SCENE_ID_INIT_PLAY:
		{
			// プレイ画面初期化
			Play.InitPlay();
			
			//マップ初期化
			InitMap();
			//マップチップ画像読み込み
			LoadMap();
			
		}
		break;
		case SCENE_ID_LOOP_PLAY:
		{
			// プレイの通常処理
			Play.StepPlay();

			// プレイの描画処理
			Play.DrawPlay();
			//マップ描画処理
			DrawMap();
		}
		break;
		case SCENE_ID_FIN_PLAY:
		{
			// プレイ終了
			Play.FinPlay();
			//マップ後処理
			FinMap();
		}
		break;
		case SCENE_ID_INIT_CLEAR:
		{
			// クリア画面初期化
			clear.InitClear();
		}
		break;
		case SCENE_ID_LOOP_CLEAR:
		{
			// クリア画面通常処理
			clear.StepClear();

			// クリア画面の描画
			clear.DrawClear();
		}
		break;
		case SCENE_ID_FIN_CLEAR:
		{
			// プレイ終了
			clear.FinClear();
		}
		break;
		case SCENE_ID_INIT_GAMEOVER:
		{
			// ゲームオーバー画面初期化
			gameover.InitGameOver();
		}
		break;
		case SCENE_ID_LOOP_GAMEOVER:
		{
			// ゲームオーバー画面通常処理
			gameover.StepGameOver();

			// ゲームオーバー画面の描画
			gameover.DrawGameOver();
		}
		break;
		case SCENE_ID_FIN_GAMEOVER:
		{
			// プレイ終了
			gameover.FinGameOver();
		}
		break;
		default:
			break;
		}

		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

